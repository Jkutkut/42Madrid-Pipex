/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 23:57:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (*(array + i))
		free(*(array + i++));
	free(array);
}

void	free_end(t_pipex *p, int endtype, char *msg)
{
	if (p->f_input != -1)
		close(p->f_input);
	if (p->f_output != -1)
		close(p->f_output);
	if (p->env_paths)
		free_array(p->env_paths);
	if (p->fds)
		free(p->fds);
	end(endtype, msg);
}