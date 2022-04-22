/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:47:55 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/22 10:06:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	init_pipex(pipex_t *pipex, int argc, char **argv, char **envp)
{
	pipex->here_doc = 0;
	pipex->cmd_count = argc - 3 - pipex->here_doc;
	pipex->fds = malloc(sizeof(int) * (pipex->cmd_count - 1) * 2);
	if (!pipex->fds)
		end(1, ERROR_MALLOC); // TODO
	pipex->cmds = argv;
	pipex->f_input = open(argv[F_INPUT], O_RDONLY);
	if (pipex->f_input == -1)
		end_error_file(argv[F_INPUT]);
	pipex->f_output = open(argv[F_OUTPUT], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->f_output == -1)
		end_error_file(argv[F_OUTPUT]);
	if (pipe(pipex->fds) == -1)
		end(1, ERROR_PIPE);
	pipex->env_paths = get_path_array(envp);
}