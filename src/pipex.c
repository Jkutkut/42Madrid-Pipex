/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:53:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 18:11:29 by jre-gonz         ###   ########.fr       */
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
		// use_pipe(p->fds[p->cmd_idx * 2 - 2], p->f_output);
		ft_putendl_fd("last fd", 2);
		ft_putstr_fd("  p->fds[", 2);
		ft_putnbr_fd(p->cmd_idx * 2 - 2, 2);
		ft_putstr_fd("]\n\n", 2);

		dup2(p->fds[p->cmd_idx * 2 - 2], STDIN);
		close(p->fds[p->cmd_idx * 2 - 2]);
		
		
		// char str[3000];
		// read(STDIN, str, 3000);
		// printf("%s\n", str);
		// return ;
	}
	else
	{
		use_pipe(p->fds[p->cmd_idx * 2 - 2], p->fds[p->cmd_idx * 2 - 1]);
		ft_putstr_fd("Index: ", 2);
		ft_putnbr_fd(p->cmd_idx * 2 - 2, 2);
		ft_putstr_fd("\n", 2);
	}
	
	p->cmd_args = ft_split(p->cmds[p->cmd_idx], ' ');
	if (!p->cmd_args)
		end(1, ERROR_MALLOC); // TODO
	p->cmd_full = get_path(p->cmd_args[0], p->env_paths);
	if (!p->cmd_full)
		end(1, ""); // TODO

	ft_putendl_fd(p->cmd_full, STDERROR);
	if (execve(p->cmd_full, p->cmd_args, p->env_paths) == -1)
		end(1, "ERROR"); // TODO
	// TODO FREE
}


// static void	child_proccess(t_pipex *pipex)
// {
// 	int		fd_file;
// 	char	*path;

// 	close(pipex->fds[PIPE_READ]);
// 	fd_file = open(pipex->cmds[F_INPUT], O_RDWR);
// 	if (fd_file == -1)
// 		end_error_file(pipex->cmds[F_INPUT]);
	
// 	dup2(fd_file, STDIN);
// 	close(fd_file);
// 	dup2(pipex->fds[PIPE_WRITE], STDOUT);
// 	// close(pipex->fds[PIPE_WRITE]); // TODO ?

// 	pipex->cmd_args = ft_split(pipex->cmds[CMD_1], ' ');
// 	if (!pipex->cmd_args)
// 		return ; // TODO
// 	path = get_path(pipex->cmd_args[0], pipex->env_paths);
// 	if (!path)
// 		return ; // TODO
// 	if (execve(path, pipex->cmd_args, pipex->env_paths) == -1)
// 	{
// 		perror("pipex: command not found: ");
// 		free(path);
// 		//TODO
// 		exit(0);
// 	}
// 	free(path);
// }


// static void	parent_proccess(int fd[2], char **argv, char **envp)
// {
// 	dup2(fd[PIPE_READ], STDIN);
// 	close(fd[PIPE_READ]);
	
	
// 	char str[3000];
// 	read(STDIN, str, 3000);
// 	printf("%s\n", str);
// }

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		end(1, ERROR_ARGC);
	init_pipex(&pipex, argc, argv, envp);
	while (++pipex.cmd_idx < pipex.cmd_count)
		exe_cmd(&pipex);
	// TODO close pipes
	waitpid(-1, NULL, 0);
	// TODO free
	return (0);
}
