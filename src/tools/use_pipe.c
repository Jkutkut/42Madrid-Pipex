/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:41:16 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/05/30 18:47:27 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tools.h"

/**
 * @brief Set's the given arguments as file descriptors of stdin and stdout.
 * Closes the given file descriptors.
 * 
 * @param fd_in File descriptor of stdin.
 * @param fd_out File descriptor of stdout.
 */
void	use_pipe(int *fd_in, int *fd_out)
{
	dup2(*fd_in, STDIN);
	dup2(*fd_out, STDOUT);
	close_pipe(fd_in);
	close_pipe(fd_out);
}
