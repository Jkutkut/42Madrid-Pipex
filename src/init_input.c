/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:38:04 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/09/20 12:17:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Analyzes if here_doc is needed and readies the input file.
 * 
 * @param pipex Structure that contains the pipex info.
 * @param argv Command line arguments.
 */
void	init_input(t_pipex *pipex, char **argv)
{
	if (pipex->heredoc)
	{
		// TODO
		//heredoc(argv[2], pipex);
		//(*argv)++;
	}
	else
	{
		// TODO
		pipex->f_input = open(argv[1], O_RDONLY);
		//if (pipex->f_input == -1)
		//	end_error_file(0, pipex, argv[1]));
	}
}
