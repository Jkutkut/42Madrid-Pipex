/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:50:54 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/09/20 12:40:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Inits the pipex struct with the given argv and envp.
 * 
 * @param pipex Structure that contains the pipex info.
 */
void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->f_input = -1;
	pipex->f_output = -1;
	pipex->cmds = NULL;
	pipex->envp = envp;
	pipex->env_paths = NULL;
	pipex->cmd_count = argc - 3 - pipex->heredoc;
	pipex->cmd_idx = 0;
	pipex->fds = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_full = NULL;
	pipex->pid = NULL;
	init_input(pipex, argv);
	// pipex->fds = malloc(sizeof(int) * (pipex->cmd_count - 1) * 2);
	// if (!pipex->fds)
	// 	free_end(pipex, 1, ERROR_MALLOC);
	// pipex->pid = malloc(sizeof(int) * pipex->cmd_count);
	// if (!pipex->pid)
	// 	free_end(pipex, 1, ERROR_MALLOC);
	// pipex->cmds = argv + 2;
	// pipex->env_paths = get_path_array(envp);
	// if (!pipex->env_paths)
	// {
	// 	pipex->env_paths = malloc(sizeof(char *));
	// 	if (!pipex->env_paths)
	// 		end(1, ERROR_MALLOC);
	// 	pipex->env_paths[0] = NULL;
	// }
	// init_output(pipex, argv[argc - 1 - pipex->here_doc]);
	// init_pipes(pipex);
	argc++;
}
