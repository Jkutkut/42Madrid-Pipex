/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:44:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/30 19:00:51 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

/**
 * @brief Ends the execution of the program
 * 
 * @param endtype Type of end (0: normal, 1: error)
 * @param msg Message to display if error.
 */
void	end(int endtype, char *msg)
{
	if (msg != NULL)
	{
		ft_putstr_fd("Error:\n  ", STDERROR);
		ft_putstr_fd(msg, STDERROR);
	}
	exit(endtype);
}
