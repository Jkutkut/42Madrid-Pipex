/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:47:55 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 23:11:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	init_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		if (pipe(&(pipex->fds[2 * i])) != 0)
			return ; // TODO
		i++;
	}
	pipex->cmd_idx = -1;
}

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->here_doc = 0;
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		pipex->here_doc = 1;
		argv++;
		argc--;
	}

	pipex->cmd_count = argc - 3 - pipex->here_doc;
	// ft_putstr_fd("cmd_count: ", 2);
	// ft_putnbr_fd(pipex->cmd_count, 2);
	// ft_putchar_fd('\n', 2);
	pipex->fds = malloc(sizeof(int) * (pipex->cmd_count - 1) * 2);
	if (!pipex->fds)
		end(1, ERROR_MALLOC);
	pipex->cmds = argv + 2;
	pipex->env_paths = get_path_array(envp);
	if (!pipex->env_paths)
		end(1, ERROR_MALLOC);

	// TODO handle here_doc
	pipex->f_input = open(*(argv - pipex->here_doc), O_RDONLY);
	if (pipex->f_input == -1)
		end_error_file(pipex, *(argv - pipex->here_doc));
	pipex->f_output = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->f_output == -1)
		end_error_file(pipex, argv[argc - 1]);

	init_pipes(pipex);
}