/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:50:54 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/10/29 18:23:56 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Inits the pipex structure with default values.
 * It also defines the amount of cmds given by input.
 * This allows the code to end the exectution at any time usign free_end.
 *
 * @param pipex Structure that contains the pipex info.
 * @param cmd_count amount of commands to execute.
 */
static void	ft_init_structure(t_pipex *pipex)
{
	pipex->f_input = -1;
	pipex->f_output = -1;
	pipex->env_paths = NULL;
	pipex->cmd_idx = 0;
	pipex->cmd_args = NULL;
	pipex->cmd_full = NULL;
}

/**
 * @brief Inits the pipex struct with the given argv and envp.
 * 
 * @param pipex Structure that contains the pipex info.
 * @param argc Argc variable from the main function.
 * @param argv Argv  variable from the main function.
 * @param envp Envp variable from the main function.
 */
void	ft_init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->envp = envp;
	ft_init_structure(pipex);
	pipex->f_output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->f_output == -1)
		ft_end_error_file(1, pipex, argv[argc - 1]);
	pipex->f_input = open(argv[1], O_RDONLY);
	if (pipex->f_input == -1)
		ft_end_error_file(0, pipex, argv[1]);
	// if (pipe(&(pipex->fds[0])) != 0 || pipe(&(pipex->fds[2])) != 0)
	if (pipe(&(pipex->fds[0])) != 0)
		ft_free_end(pipex, 1, ERROR_PIPE_INIT);
	pipex->cmds[0] = *(argv + 2);
	pipex->cmds[1] = *(argv + 3);
	pipex->env_paths = ft_get_path_array(envp);
	if (!pipex->env_paths)
	{
		pipex->env_paths = malloc(sizeof(char *));
		if (!pipex->env_paths)
			ft_free_end(pipex, 1, ERROR_MALLOC);
		pipex->env_paths[0] = NULL;
	}
}
