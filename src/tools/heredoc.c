/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:44:16 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/06 18:45:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"
#define ERROR_HEREDOC "here_doc failed"
#define HEREDOC_FILE ".heredoc.tmp"
#define HEREDOC "heredoc> "

char	*store_next_line(char **buf, int fd)
{
	char *nl;
	char *tmp;

	nl = get_next_line(fd);
	if (!nl)
		return (nl);
	tmp = *buf;
	*buf = ft_strjoin(*buf, nl);
	return (*buf);
}

void	heredoc(char *delim, t_pipex *pipex)
{
	int		f;
	char	*buf;

	f = open(HEREDOC_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (f <= 0)
		free_end(pipex, 1, ERROR_HEREDOC);
	while (1)
	{
		write(1, HEREDOC, 9);
		if (store_next_line(&buf, STDIN) < 0)
			free_end(pipex, 1, ERROR_HEREDOC);
		if (!ft_strncmp(delim, buf, ft_strlen(delim) + 1))
			break ;
		ft_putendl_fd(buf, f);
		free(buf);
	}
	free(buf);
	close(f);
	pipex->f_input = open(HEREDOC_FILE, O_RDONLY);
	if (pipex->f_input <= 0)
	{
		unlink(HEREDOC_FILE);
		free_end(pipex, 1, ERROR_HEREDOC);
	}	
}
