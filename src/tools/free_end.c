/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/30 22:06:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

/**
 * @brief Frees all the alocated memory and ends the process with the given
 * endtype and message.
 * 
 * If message is NULL, the message is omitted.
 * 
 * @param p The pipex struct used.
 * @param endtype The exit code.
 * @param msg The message to print if given.
 */
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
