/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:48:50 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/30 22:08:14 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

char	*get_path(char *cmd, char **path_array)
{
	int		i;
	char	*path;

	if (!path_array || !cmd)
		return (NULL);
	i = 0;
	if (access(cmd, 0) == 0)
		return (cmd);
	while (path_array[i])
	{
		path = make_path(path_array[i], cmd);
		if (!path)
			return (NULL);
		if (access(path, 0) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
