/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_error_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:18:37 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 23:15:36 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	end_error_file(int type, t_pipex *pipex, char *file)
{
	if (type == 0)
		perror("No such file or directory: ");
	else
		perror("Not able to open: ");
	perror(file);
	free_end(pipex, 1, "\n");
}