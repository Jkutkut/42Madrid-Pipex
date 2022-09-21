/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:02:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/09/21 09:47:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Frees the given char array.
 * 
 * @param array The array to free.
 */
void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (*(array + i))
		free(*(array + i++));
	free(array);
}
