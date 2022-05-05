/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:44:16 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/05 17:21:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#define ERROR_HEREDOC "here_doc failed"
#define HEREDOC_FILE ".heredoc.tmp"
#define HEREDOC "heredoc> "

void	heredoc(char *argv, t_pipex *pipex)
{
	int		f;
	char	*buf;

	f = open(HEREDOC_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (f <= 0)
		free_end(pipex, 1, ERROR_HEREDOC);
	while (1)
	{
		write(1, HEREDOC, 9);
		if (get_next_line(STDIN, &buf) < 0)
			free_end(pipex, 1, ERROR_HEREDOC);
		if (!ft_strncmp(argv, buf, ft_strlen(argv) + 1))
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
