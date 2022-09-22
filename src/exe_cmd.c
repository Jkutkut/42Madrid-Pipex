/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:18:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/09/22 09:32:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief TODO
 *
 *  Note: Pipes are closed before the cmd is executed because we have them
 *  on stdin and stdout.
 *
 */
int	ft_exe_cmd(t_pipex *p)
{
	int	pid;

	pid = fork();
	if (pid)
		return (pid);
	// TODO refactor order of pipex to be in line
	// if (p->cmd_idx == 0)
	// 	use_pipe(&p->f_input, &p->fds[1]);
	// else if (p->cmd_idx == p->cmd_count - 1)
	// 	use_pipe(&p->fds[p->cmd_idx * 2 - 2], &p->f_output);
	// else
	// 	use_pipe(&p->fds[p->cmd_idx * 2 - 2], &p->fds[p->cmd_idx * 2 + 1]);
	ft_close_fds(p);
	p->cmd_args = ft_split(p->cmds[p->cmd_idx], ' ');
	if (!p->cmd_args)
		ft_free_end(p, 1, ERROR_MALLOC);
	// p->cmd_full = get_path(p->cmd_args[0], p->env_paths);
	// ft_putendl_fd(p->cmd_full, 2); // TODO debug
	// if (!p->cmd_full)
	// 	free_end(p, ERROR_CNF_CODE, ERROR_CNF);
	// if (execve(p->cmd_full, p->cmd_args, p->envp) == -1)
	// 	free_end(p, 1, ERROR_EXE_CMD);
	return (-1); // TODO Check if this is ok. This line should never be executed.
}
