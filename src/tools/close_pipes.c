/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:11:37 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/06 18:45:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

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
	close_pipe(&p->f_input);
	close_pipe(&p->f_output);
}