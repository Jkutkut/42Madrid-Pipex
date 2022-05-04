/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:48:50 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/04 18:06:43 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static char	*make_path(char *path, char *cmd)
{
	int		path_len;
	int		cmd_len;
	char	*str;

	if (!path || !cmd)
		return (NULL);
	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	str = (char *) malloc(sizeof(char) * (path_len + cmd_len + 2));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, path, path_len + 1);
	ft_strlcpy(str + path_len, "/", 2);
	ft_strlcpy(str + path_len + 1, cmd, cmd_len + 1);
	return (str);
}

char	*get_path(char *cmd, char **path_array)
{
	int		i;
	char	*path;
	int		fd;

	if (!path_array || !cmd)
		return (NULL);
	i = 0;
	fd = open(cmd, O_RDONLY);
	if (fd >= 0)
	{
		close(fd);
		return (ft_strdup(cmd));
	}
	while (path_array[i])
	{
		path = make_path(path_array[i], cmd);
		if (!path)
			return (NULL);
		fd = open(path, O_RDONLY);
		if (fd >= 0)
		{
			close(fd);
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}
