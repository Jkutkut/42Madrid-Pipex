/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:41:16 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 14:03:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

/**
 * @brief Set's the given arguments as file descriptors of stdin and stdout.
 * Closes the given file descriptors.
 * 
 * @param fd_in File descriptor of stdin.
 * @param fd_out File descriptor of stdout.
 */
void	use_pipe(int fd_in, int fd_out)
{
	dup2(fd_in, STDIN);
	dup2(fd_out, STDOUT);
	close(fd_in);
	close(fd_out);
}