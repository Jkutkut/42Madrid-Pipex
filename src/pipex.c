/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:53:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/22 08:36:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_proccess(pipex_t *pipex)
{
	int		fd_file;
	char	*path;

	close(pipex->fds[PIPE_READ]);
	fd_file = open(pipex->cmds[F_INPUT], O_RDWR);
	if (fd_file == -1)
		end_error_file(pipex->cmds[F_INPUT]);
	
	dup2(fd_file, STDIN);
	close(fd_file);
	dup2(pipex->fds[PIPE_WRITE], STDOUT);
	// close(pipex->fds[PIPE_WRITE]); // TODO ?

	pipex->cmd_args = ft_split(pipex->cmds[CMD_1], ' ');
	if (!pipex->cmd_args)
		return ; // TODO
	path = get_path(pipex->cmd_args[0], pipex->env_paths);
	if (!path)
		return ; // TODO
	if (execve(path, pipex->cmd_args, pipex->env_paths) == -1)
	{
		perror("pipex: command not found: ");
		free(path);
		//TODO
		exit(0);
	}
	free(path);
}


static void	parent_proccess(int fd[2], char **argv, char **envp)
{
	dup2(fd[PIPE_READ], STDIN);
	close(fd[PIPE_READ]);
	
	
	char str[3000];
	read(STDIN, str, 3000);
	printf("%s\n", str);
}

int	main(int argc, char **argv, char **envp)
{
	pipex_t	pipex;

	if (argc != 5)
		end(1, ERROR_ARGC);
	init_pipex(&pipex, argc, argv, envp);
	pipex.pid = fork();
	if (pipex.pid == -1)
		perror(ERROR_FORK);
	if (pipex.pid == 0)
		child_proccess(&pipex);
	else
		parent_proccess(pipex.fds, argv, envp);
		// parent_proccess(pipex);
	
	// waitpid(pipex->pid, NULL, 0);
	return (0);
}
