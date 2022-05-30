/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:42:26 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/30 21:42:33 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

/**
 * @brief Having in mind here_doc, it readies the output file to be used.
 * 
 * @param pipex Structure that contains the pipex info.
 * @param path Path to the output file.
 */
void	init_output(t_pipex *pipex, char *path)
{
	int	f_out_oflag;

	if (pipex->here_doc)
		f_out_oflag = O_WRONLY | O_CREAT | O_APPEND;
	else
		f_out_oflag = O_CREAT | O_RDWR | O_TRUNC;
	pipex->f_output = open(path, f_out_oflag, 0000644);
	if (pipex->f_output == -1)
		end_error_file(1, pipex, path);
}