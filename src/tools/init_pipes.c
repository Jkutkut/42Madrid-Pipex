/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:18:55 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/01 14:35:24 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

/**
 * @brief Creates the pipes need to communicate the processes.
 * 
 * @param pipex Structure that contains will contain the pipes.
 */
void	init_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		if (pipe(&(pipex->fds[2 * i])) != 0)
			free_end(pipex, 1, ERROR_PIPE_INIT);
		i++;
	}
	pipex->cmd_idx = -1;
}
