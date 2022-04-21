/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_error_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:18:37 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/21 12:20:16 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	end_error_file(char *file)
{
	perror("No such file or directory: ");
	perror(file);
	exit(1);
}