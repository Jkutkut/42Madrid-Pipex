/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:11:37 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 23:59:20 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	close_pipe(int *fd)
{
	if (*fd == -1)
		return ;
	close(*fd);
	*fd = -1;
}

void	close_pipes(t_pipex *p)
{
	int i;

	i = 0;
	while (i < p->cmd_count - 1)
	{
		close_pipe(&p->fds[2 * i]);
		close_pipe(&p->fds[2 * i + 1]);
		i++;
	}
}