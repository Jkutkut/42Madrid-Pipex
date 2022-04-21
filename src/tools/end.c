/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:44:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/21 09:18:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

/**
 * @brief Ends the execution of the program
 * 
 * @param endtype Type of end (0: normal, 1: error)
 * @param msg Message to display 
 */
void	end(int endtype, char *msg)
{
	if (endtype == 1)
		ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(msg, endtype + 1);
	exit(endtype);
}