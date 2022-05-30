/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/30 22:02:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

void	free_end(t_pipex *p, int endtype, char *msg)
{
	if (p->f_input != -1)
		close(p->f_input);
	if (p->f_output != -1)
		close(p->f_output);
	if (p->env_paths)
		free_array(p->env_paths);
	if (p->fds)
	{
		close_pipes(p);
		free(p->fds);
	}
	end(endtype, msg);
}
