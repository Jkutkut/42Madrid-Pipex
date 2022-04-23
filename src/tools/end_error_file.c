/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_error_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:18:37 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 23:02:30 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	end_error_file(t_pipex *pipex, char *file)
{
	perror("No such file or directory: ");
	perror(file);
	free_end(pipex, 1, "\n");
}