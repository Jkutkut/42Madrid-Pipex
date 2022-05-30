/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:53:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/30 18:38:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exe_cmd(t_pipex *p)
{
	p->pid = fork();
	if (p->pid)
		return ;
	if (p->cmd_idx == 0)
		use_pipe(&p->f_input, &p->fds[1]);
	else if (p->cmd_idx == p->cmd_count - 1)
		use_pipe(&p->fds[p->cmd_idx * 2 - 2], &p->f_output);
	else
		use_pipe(&p->fds[p->cmd_idx * 2 - 2], &p->fds[p->cmd_idx * 2 + 1]);
	close_pipes(p); // Close now, we have it on stdin and stdout
	p->cmd_args = ft_split(p->cmds[p->cmd_idx], ' ');
	if (!p->cmd_args)
		free_end(p, 1, ERROR_MALLOC);
	p->cmd_full = get_path(p->cmd_args[0], p->env_paths);
	if (!p->cmd_full)
		free_end(p, ERROR_CNF_CODE, ERROR_CNF);

	ft_putendl_fd(p->cmd_full, STDERROR); // TODO DEBUG
	if (execve(p->cmd_full, p->cmd_args, p->env_paths) == -1) // ends execution if successful
		free_end(p, 1, ERROR_EXE_CMD);
}

static int wexitstatus(int status)
{
	return (((status) & 0xff00) >> 8);
}

/*
static void	check_this(void)
{
	// system("lsof -c pipex");
	system("ps -lf");
}
*/

/**
 * @brief Simulates the pipe command from linux.
 * 
 * ./pipex file1 cmd1 ... cmdn file2
 * 
 * ./pipex here_doc LIMITER cmd1 ... cmdn file2
 */
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	// atexit(check_this);
	if (argc < 5)
		end(1, ERROR_ARGC);
	init_pipex(&pipex, argc, argv, envp);
	while (++pipex.cmd_idx < pipex.cmd_count)
		exe_cmd(&pipex);
	int result = 0;
	int idx = 0;
	while (++idx < pipex.cmd_count - 1)
		waitpid(-1, NULL, 0);
	waitpid(-1, &result, 0);
	free_end(&pipex, wexitstatus(result), NULL);
	return (0);
}
