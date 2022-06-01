/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:38:04 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/01 14:34:59 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

/**
 * @brief Analyzes if here_doc is needed and readies the input file.
 * 
 * @param pipex Structure that contains the pipex info.
 * @param argv Command line arguments.
 */
void	init_input(t_pipex *pipex, char ***argv)
{
	if (!ft_strncmp((*argv)[1], "here_doc", 9))
	{
		ft_putendl_fd("open heredoc", STDIN);
		pipex->here_doc = 1;
		heredoc((*argv)[2], pipex);
		(*argv)++;
	}
	else
	{
		ft_putendl_fd("open no heredoc", STDIN);
		pipex->f_input = open((*argv)[1], O_RDONLY);
		if (pipex->f_input == -1)
			end_error_file(0, pipex, *((*argv) + 1));
	}
}
