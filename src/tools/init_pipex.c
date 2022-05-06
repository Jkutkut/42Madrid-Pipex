/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:47:55 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/06 17:39:36 by jre-gonz         ###   ########.fr       */
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
			free_end(pipex, 1, ERROR_PIPE_INIT);
		i++;
	}
	pipex->cmd_idx = -1;
}

/**
 * @brief Inits the pipex struct with the given argv and envp.
 */
void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->here_doc = 0;
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		pipex->here_doc = 1;
		heredoc(argv[2], pipex);
	}
	else
	{
		pipex->f_input = open(argv[1], O_RDONLY);
		if (pipex->f_input == -1)
			end_error_file(0, pipex, *(argv + 1));
	}

	pipex->cmd_count = argc - 3 - pipex->here_doc;
	pipex->fds = malloc(sizeof(int) * (pipex->cmd_count - 1) * 2);
	if (!pipex->fds)
		end(1, ERROR_MALLOC);
	pipex->cmds = argv + 2;
	pipex->env_paths = get_path_array(envp);
	if (!pipex->env_paths)
	{
		pipex->env_paths = malloc(sizeof(char *));
		if (!pipex->env_paths)
			end(1, ERROR_MALLOC);
	}

	if (pipex->here_doc)
		pipex->f_output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		pipex->f_output = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (pipex->f_output == -1)
		end_error_file(1, pipex, argv[argc - 1]);
	init_pipes(pipex);
}
