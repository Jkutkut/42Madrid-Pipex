/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:15:28 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/09/19 15:50:36 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	// int		result;
	// int		idx;

	if (argc < 5)
	 	end(1, ERROR_ARGC);
	init_pipex(&pipex, argc, argv, envp);
	// while (++pipex.cmd_idx < pipex.cmd_count)
	// 	pipex.pid[pipex.cmd_idx - 1] = exe_cmd(&pipex);
	// idx = 0;
	// while (idx++ < pipex.cmd_count - 1)
	// 	waitpid(pipex.pid[idx], NULL, 0);
	// waitpid(pipex.pid[idx], &result, 0);
	// if (wifexited(result))
	// 	free_end(&pipex, wexitstatus(result), NULL);
	// free_end(&pipex, EXIT_SUCCESS, NULL);
	return (EXIT_SUCCESS);
}
