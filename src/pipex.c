/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:53:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 12:35:42 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	end_error_file(char *file)
{
	ft_putstr_fd("No such file or directory: ", STDERROR);
	ft_putendl_fd(file, STDERROR);
	exit(1);
}

static void	child_proccess(int fd[2], char **argv, char **envp)
{
	int		fd_file;
	char	*path;

	close(fd[PIPE_READ]);
	fd_file = open(argv[F_INPUT], O_RDWR);
	if (fd_file == -1)
		end_error_file(argv[F_INPUT]);
	
	dup2(fd_file, STDIN);
	close(fd_file);
	// dup2(fd[PIPE_WRITE], STDOUT);
	// close(fd[PIPE_WRITE]);
	
	path = get_path(argv[CMD_1], envp);
	printf("path: %s\n", path);
}

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	fds[2];

	if (argc != 5)
		end(1, ERROR_ARGC);
	if (pipe(fds) == -1)
		end(1, ERROR_PIPE);
	pid = fork();
	if (pid == -1)
		perror(ERROR_FORK);
	else if (pid == 0)
		child_proccess(fds, argv, envp);
	else
		printf("Parent with pid %d\n", pid);
	// waitpid(pid, NULL, 0);
	return (0);
}