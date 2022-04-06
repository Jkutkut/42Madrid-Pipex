/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:53:03 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/06 10:54:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	// int	fds[2];

	if (argc != 5)
		end(1, ERROR_ARGC);
	// pipe(fds);
	pid = fork();
	if (pid == -1)
		perror(ERROR_FORK);
	else if (pid == 0)
		printf("Parent\n");
	else
		printf("Child with pid %d\n", pid);
	waitpid(pid, NULL, 0);
	return (0);
}