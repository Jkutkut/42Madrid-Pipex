/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:15:28 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/09/21 16:32:39 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO norminette ft_
#include "pipex.h"

/**
 * @brief Checks that the given arguments are valid.
 * Also detects if heredoc present (1 if heredoc, 0 else).
 * min cases:
 *   no here_doc: pipex file.in cmd1 cmd2 outfile -> argc == 5
 *      here_doc: pipex heredoc end cmd1 cmd2 outfile -> argc == 6
 * @param argc Argc from the main function.
 * @param argv Argv from the main function.
 * @returns 1 if valid, 0 otherwise. 
 */
static int	ft_check_arg(int argc, char **argv, int *heredoc)
{
	if (argc < 5)
		return (0);
	*heredoc = 0;
	if (!ft_strncmp(argv[1], HEREDOC, ft_strlen(HEREDOC)))
	{
		*heredoc = 1;
		if (argc < 6)
			return (0);
	}
	return (1);
}

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

	if (!ft_check_arg(argc, argv, &pipex.heredoc))
	 	ft_end(1, ERROR_ARGC);
	ft_init_pipex(&pipex, argc, argv, envp);
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
