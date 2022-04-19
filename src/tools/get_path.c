/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:48:50 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 16:03:40 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/tools.h"

static void	free_string_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

// static char	*get_cmd(char *cmd_full)
// {
// 	char	**cmd_array;
// 	char	*cmd;

// 	cmd_array = ft_split(cmd_full, ' ');
// 	if (!cmd_array)
// 		return (NULL);
// 	cmd = ft_strdup(cmd_array[0]);
// 	free_string_arr(cmd_array);
// 	return (cmd);
// }

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

static char	*end_get_path(char *cmd, char **path_array, char *v)
{
	// if (cmd)
	// 	free(cmd);
	free_string_arr(path_array);
	return (v);
}

char	*get_path(char *cmd, char **envp)
{
	char	**path_array;
	int		i;
	char	*path;
	int		fd;

	path_array = get_path_array(envp);
	if (!path_array || !cmd)
		return (end_get_path(cmd, path_array, NULL));
	i = 0;
	while (path_array[i])
	{
		path = make_path(path_array[i], cmd);
		if (!path)
			return (end_get_path(cmd, path_array, NULL));
		fd = open(path, O_RDONLY);
		if (fd >= 0)
		{
			close(fd);
			return end_get_path(cmd, path_array, path);
		}
		free(path);
		i++;
	}
	return end_get_path(cmd, path_array, NULL);
}