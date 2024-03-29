/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:18:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/10/29 19:17:24 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Executes the p->cmd_idº command.
 *
 *  Note: Pipes are closed before the cmd is executed because we have them
 *  on stdin and stdout.
 *  Note2: Pipes use the order given by the pipe cmd. This means:
 *  	pipefd[0] refers to the read end of the pipe.
 *  	pipefd[1] refers to the write end of the pipe.
 *  @param p
 *  @return pid of the child generated to execute the command.
 */
int	ft_exe_cmd(t_pipex *p)
{
	int	pid;

	pid = fork();
	if (pid)
		return (pid);
	if (p->cmd_idx == 0)
		ft_use_pipe(&p->f_input, &p->fds[1]);
	else
		ft_use_pipe(&p->fds[0], &p->f_output);
	ft_close_fds(p);
	p->cmd_args = ft_split(p->cmds[p->cmd_idx], ' ');
	if (!p->cmd_args)
		ft_free_end(p, 1, ERROR_MALLOC);
	p->cmd_full = ft_get_path(p->cmd_args[0], p->env_paths);
	if (!p->cmd_full)
		ft_free_end(p, ERROR_CNF_CODE, ERROR_CNF);
	execve(p->cmd_full, p->cmd_args, p->envp);
	return (ft_free_end(p, 1, ERROR_EXE_CMD));
}
