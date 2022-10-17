/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpids.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:06:35 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/10/17 20:16:38 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/**
 * TODO
 */

int ft_waitpids(t_pipex *p)
{
	pid_t	waited_pid;
	int		result;
	int 	status;

	p->cmd_idx = 0;
	while (p->cmd_idx < p->cmd_count) {
		waited_pid = waitpid(p->pid[p->cmd_idx++], &status, 0);
		if (waited_pid == p->pid[p->cmd_count - 1])
			result = status;
	}
	return result;
}
