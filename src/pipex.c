/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:53:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/26 11:02:14 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exe_cmd(t_pipex *p)
{
	p->pid = fork();
	if (p->pid)
		return ;
	if (p->cmd_idx == 0)
		use_pipe(p->f_input, p->fds[1]);
	else if (p->cmd_idx == p->cmd_count - 1)
	{
		use_pipe(p->fds[p->cmd_idx * 2 - 2], p->f_output);
		ft_putendl_fd("last fd", 2);
		ft_putstr_fd("  p->fds[", 2);
		ft_putnbr_fd(p->cmd_idx * 2 - 2, 2);
		ft_putstr_fd("]\n\n", 2);
	}
	else
	{
		use_pipe(p->fds[p->cmd_idx * 2 - 2], p->fds[p->cmd_idx * 2 + 1]);
		ft_putstr_fd("Index: ", 2);
		ft_putnbr_fd(p->cmd_idx * 2 - 2, 2);
		ft_putstr_fd("\n", 2);
	}
	// waitpid(-1, NULL, 0);
	p->cmd_args = ft_split(p->cmds[p->cmd_idx], ' ');
	if (!p->cmd_args)
		free_end(p, 1, ERROR_MALLOC);
	p->cmd_full = get_path(p->cmd_args[0], p->env_paths);
	if (!p->cmd_full)
		free_end(p, 1, ERROR_CNF);

	ft_putendl_fd(p->cmd_full, STDERROR);
	if (execve(p->cmd_full, p->cmd_args, p->env_paths) == -1)
		free_end(p, 1, ERROR_EXE_CMD);
	
	close_pipes(p);
	free_end(p, 0, NULL);
}

// system("lsof -c pipex");

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		end(1, ERROR_ARGC);
	init_pipex(&pipex, argc, argv, envp);
	while (++pipex.cmd_idx < pipex.cmd_count)
		exe_cmd(&pipex);
	waitpid(-1, NULL, 0);
	free_end(&pipex, 0, NULL);
	return (0);
}
