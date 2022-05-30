/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:20:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/30 19:00:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

char	**get_path_array(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_split(ft_strchr(envp[i], '/'), ':'));
		i++;
	}
	return (NULL);
}
