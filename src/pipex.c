/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:15:28 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/10/17 19:20:31 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO norminette ft_
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
	int		result;

	if (!ft_check_arg(argc, argv, &pipex.heredoc))
		ft_end(1, ERROR_ARGC);
	ft_init_pipex(&pipex, argc, argv, envp);
	while (pipex.cmd_idx < pipex.cmd_count)
	{
		pipex.pid[pipex.cmd_idx] = ft_exe_cmd(&pipex);
		pipex.cmd_idx++;
	}
	waitpid(-1, &result, 0);
	// system("ps -l"); // TODO check all processes have ended
	// TODO WEXITSTATUS
	return (ft_free_end(&pipex, WEXITSTATUS(result), NULL));
}
