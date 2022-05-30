/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_error_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:18:37 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/30 19:00:25 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

void	end_error_file(int type, t_pipex *pipex, char *file)
{
	char	error_msg[1024];

	if (type == 0)
		ft_memmove(error_msg, "No such file or directory: ", 28);
	else
		ft_memmove(error_msg, "Not able to open: ", 19);
	ft_strlcat(error_msg, file, ft_strlen(error_msg) + ft_strlen(file) + 1);
	free_end(pipex, 1, error_msg);
}
