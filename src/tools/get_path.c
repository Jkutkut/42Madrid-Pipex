/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:48:50 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/21 15:26:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static char	*free_string_arr(char **arr, char *v)
{
	int	i;

	if (!arr)
		return v;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (v);
}

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

char	*get_path(char *cmd, char **envp)
{
	char	**path_array;
	int		i;
	char	*path;
	int		fd;

	path_array = get_path_array(envp);
	if (!path_array || !cmd)
		return (free_string_arr(path_array, NULL));
	i = 0;
	while (path_array[i])
	{
		path = make_path(path_array[i], cmd);
		if (!path)
			return (free_string_arr(path_array, NULL));
		fd = open(path, O_RDONLY);
		if (fd >= 0)
		{
			close(fd);
			return free_string_arr(path_array, path);
		}
		free(path);
		i++;
	}
	return free_string_arr(path_array, NULL);
}