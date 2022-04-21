/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:53:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/21 16:33:49 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_proccess(int fd[2], char **argv, char **envp)
{
	int		fd_file;
	char	*path;
	char	**cmd;

	close(fd[PIPE_READ]);
	fd_file = open(argv[F_INPUT], O_RDWR);
	if (fd_file == -1)
		end_error_file(argv[F_INPUT]);
	
	dup2(fd_file, STDIN);
	close(fd_file);
	dup2(fd[PIPE_WRITE], STDOUT);
	close(fd[PIPE_WRITE]);
	
	cmd = ft_split(argv[CMD_1], ' ');
	if (!cmd)
		return ; // TODO
	path = get_path(cmd[0], envp);
	if (!path)
		return ; // TODO
	printf("path: %s\n", path);
	printf("cmd: %p %s\n", cmd[0], cmd[0]);
	int i = 1;
	while (cmd[i])
	{
		printf("cmd[%d]: %s\n", i, cmd[i]);
		i++;
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", STDERROR);
		//TODO
		exit(0);
	}
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
	pipex_t		*pipex;

	if (argc != 5)
		end(1, ERROR_ARGC);
	pipex = init_pipex(argc, argv, envp);
	pipex->pid = fork();
	if (pipex->pid == -1)
		perror(ERROR_FORK);
	if (pipex->pid == 0)
		child_proccess(pipex->fds, argv, envp);
		// child_proccess(pipex);
	else
		parent_proccess(pipex->fds, argv, envp);
		// parent_proccess(pipex);
	
	waitpid(pipex->pid, NULL, 0);
	return (0);
}
