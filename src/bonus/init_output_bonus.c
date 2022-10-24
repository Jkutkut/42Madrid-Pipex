/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_output_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:42:26 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/10/24 11:00:05 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * @brief Having in mind heredoc, it readies the output file to be used.
 * 
 * @param pipex Structure that contains the pipex info.
 * @param path Path to the output file.
 */
void	ft_init_output(t_pipex *pipex, char *path)
{
	int	f_out_oflag;

	if (pipex->heredoc)
		f_out_oflag = O_WRONLY | O_CREAT | O_APPEND;
	else
		f_out_oflag = O_CREAT | O_RDWR | O_TRUNC;
	pipex->f_output = open(path, f_out_oflag, 0000644);
	if (pipex->f_output == -1)
		ft_end_error_file(1, pipex, path);
}
