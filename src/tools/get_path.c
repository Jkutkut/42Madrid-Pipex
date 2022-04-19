/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:48:50 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 11:13:58 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tools.h"

static char	*free_string_arr(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char	*get_cmd(char *cmd_full)
{
	char	**cmd_array;
	char	*cmd;

	cmd_array = ft_split(cmd_full, " ");
	if (!cmd_array)
		return (NULL);
	cmd = ft_strdup(cmd_array[0]);
	free_string_arr(cmd_array);
	return (cmd);
}

static char	make_path(char *path, char *cmd)
{
	size_t	path_len;
	size_t	cmd_len;
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

char	*get_path(char *cmd_full, char **envp)
{
	char	**path_array;
	char	*cmd;
	int		i;
	char	*path;

	cmd = get_cmd(cmd_full);
	path_array = get_path_array(envp);
	if (!path_array || !cmd)
	{
		if (cmd)
			free(cmd);
		return free_string_arr(path_array);
	}
	i = 0;
	while (path_array[i])
	{
		path = make_path(path_array[i], cmd);
		if (!path)
		{
			free(cmd);
			return free_string_arr(path_array);
		}
		i++;
	}
	return (NULL);
}