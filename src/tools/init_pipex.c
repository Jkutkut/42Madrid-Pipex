/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:47:55 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/30 21:38:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

static void	init_output(t_pipex *pipex, char *path)
{
	int	f_out_oflag;

	if (pipex->here_doc)
		f_out_oflag = O_WRONLY | O_CREAT | O_APPEND;
	else
		f_out_oflag = O_CREAT | O_RDWR | O_TRUNC;
	pipex->f_output = open(path, f_out_oflag, 0000644);
	if (pipex->f_output == -1)
		end_error_file(1, pipex, path);
}

/**
 * @brief Inits the pipex struct with the given argv and envp.
 * 
 * @param pipex Structure that contains the pipex info.
 */
void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->env_paths = NULL;
	pipex->here_doc = 0;
	init_input(pipex, &argv);
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
		pipex->env_paths[0] = NULL;
	}
	init_output(pipex, argv[argc - 1 - pipex->here_doc]);
	init_pipes(pipex);
}
