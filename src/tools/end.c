/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:44:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 22:14:59 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

/**
 * @brief Ends the execution of the program
 * 
 * @param endtype Type of end (0: normal, 1: error)
 * @param msg Message to display if error.
 */
void	end(int endtype, char *msg)
{
	if (endtype == 1)
	{
		perror("Error:\n  ");
		perror(msg);
	}
	exit(endtype);
}