/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:47:55 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 14:02:16 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	init_pipes(pipex_t *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		if (pipe(&(pipex->fds[2 * i])) != 0)
			return ; // TODO
		i++;
	}
	pipex->fd_idx = 0;
}

void	init_pipex(pipex_t *pipex, int argc, char **argv, char **envp)
{
	pipex->here_doc = 0;
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		pipex->here_doc = 1;
		argv++;
		argc--;
	}

	pipex->cmd_count = argc - 3 - pipex->here_doc;
	pipex->fds = malloc(sizeof(int) * (pipex->cmd_count - 1) * 2);
	if (!pipex->fds)
		end(1, ERROR_MALLOC); // TODO

	pipex->cmds = argv;
	pipex->env_paths = get_path_array(envp);

	pipex->f_input = open(argv[F_INPUT], O_RDONLY);
	if (pipex->f_input == -1)
		end_error_file(argv[F_INPUT]); // TODO
	pipex->f_output = open(argv[F_OUTPUT], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->f_output == -1)
		end_error_file(argv[F_OUTPUT]); // TODO

	init_pipes(pipex);
}