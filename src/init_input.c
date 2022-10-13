/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:38:04 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/10/13 13:10:23 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Analyzes if here_doc is needed and readies the input file.
 * 
 * @param pipex Structure that contains the pipex info.
 * @param argv Command line arguments.
 */
void	ft_init_input(t_pipex *pipex, char ***argv)
{
	pipex->heredoc = ft_strncmp((*argv)[1], HEREDOC, ft_strlen(HEREDOC)) == 0;
	if (pipex->heredoc)
	{
		ft_putstr_fd("Heredoc used\n", 2);
		ft_heredoc((*argv)[2], pipex);
		(*argv)++;
		pipex->cmd_count--;
	}
	else
	{
		ft_putstr_fd("File used\n", 2);
		pipex->f_input = open((*argv)[1], O_RDONLY);
		if (pipex->f_input == -1)
			ft_end_error_file(0, pipex, (*argv)[1]);
	}
}
