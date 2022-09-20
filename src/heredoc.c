/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:44:16 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/09/20 13:59:50 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*store_next_line(char **buf, int fd)
{
	*buf = get_next_line(fd);
	if (!*buf)
		return (NULL);
	return (*buf);
}

static int	isdelimeter(char *delimeter, char *buf)
{
	int	delim_len;
	int	buf_len;

	delim_len = ft_strlen(delimeter);
	buf_len = ft_strlen(buf);
	if (delim_len + 1 != buf_len)
		return (0);
	if (ft_strncmp(delimeter, buf, delim_len))
		return (0);
	if (buf[delim_len] != '\n')
		return (0);
	return (1);
}

static void	get_heredoc(char *delim, t_pipex *pipex, char **buf, int f)
{
	while (1)
	{
		write(1, HEREDOC_SHELL, 9);
		if (!store_next_line(buf, STDIN))
			free_end(pipex, 1, ERROR_HEREDOC);
		if (isdelimeter(delim, *buf))
			break ;
		ft_putendl_fd(*buf, f);
		if (*buf)
			free(*buf);
	}
	free(*buf);
}

void	heredoc(char *delim, t_pipex *pipex)
{
	int		f;
	char	*buf;

	buf = NULL;
	f = open(HEREDOC_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (f <= 0)
		free_end(pipex, 1, ERROR_HEREDOC);
	get_heredoc(delim, pipex, &buf, f);
	close(f);
	pipex->f_input = open(HEREDOC_FILE, O_RDONLY);
	if (pipex->f_input == -1)
	{
		unlink(HEREDOC_FILE);
		free_end(pipex, 1, ERROR_HEREDOC);
	}
}
