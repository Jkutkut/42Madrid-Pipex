/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:53:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 14:55:29 by jre-gonz         ###   ########.fr       */
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
		use_pipe(p->fds[p->cmd_idx * 2], p->f_output);
	else
		use_pipe(p->fds[p->cmd_idx], p->fds[p->cmd_idx + 1]);
	
	
	// p->cmd = get_path(, p->env_paths);
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
	// waitpid(pipex->pid, NULL, 0);
	return (0);
}
