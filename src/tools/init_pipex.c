/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:47:55 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/21 12:10:18 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pipex_t	*init_pipex(char *cmd_full, char **envp)
{
	pipex_t	*pipex;

	pipex = (pipex_t *)malloc(sizeof(pipex_t));
	if (!pipex)
		end(1, ERROR_MALLOC);
	
	return (pipex);
}