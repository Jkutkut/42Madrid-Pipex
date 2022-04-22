/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:47:55 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/21 20:57:36 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

pipex_t	*init_pipex(int argc, char **argv, char **envp)
{
	pipex_t	*pipex;

	pipex = (pipex_t *)malloc(sizeof(pipex_t));
	if (!pipex)
		end(1, ERROR_MALLOC);
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
	return (pipex);
}