/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:15:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/24 15:54:32 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

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
	ft_printf("freeend\n");
	if (p->f_input != -1)
		close(p->f_input);
	ft_printf("freeend finput done\n");
	if (p->f_output != -1)
		close(p->f_output);
	ft_printf("freeend foutput done\n");
	if (p->env_paths)
		free_array(p->env_paths);
	ft_printf("freeend pre fds\n");
	if (p->fds)
	{
		close_pipes(p);
		free(p->fds);
	}
	ft_printf("freeend posts fds\n");
	end(endtype, msg);
}