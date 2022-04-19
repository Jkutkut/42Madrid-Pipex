/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:53:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 09:48:33 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	end_error_file(char *file)
{
	ft_putstr_fd("Error when opening the file: ", 2);
	ft_putendl_fd(file, 2);
	exit(1);
}

static void	child_proccess(int fd[2], char **argv, char **env)
{
	int	fd_file;

	close(fd[PIPE_READ]);
	fd_file = open(argv[F_INPUT], O_RDWR);
	if (fd_file == -1)
		end_error_file(argv[F_INPUT]);
	dup2(fd_file, STDIN);
	close(fd_file);
	dup2(fd[PIPE_WRITE], STDOUT);
	close(fd[PIPE_WRITE]);
	
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
		printf("Child\n");
	else
		printf("Parent with pid %d\n", pid);
	// waitpid(pid, NULL, 0);
	return (0);
}