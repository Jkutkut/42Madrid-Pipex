/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:57:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 10:43:32 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include <fcntl.h>
# include <string.h>

# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>

# include "../include/pipex_msg.h"

# include "../src/libft/libft.h"

# include "tools.h"

# define STDIN 0
# define STDOUT 1
# define STDERROR 2

# define F_INPUT 1
# define CMD_1 2
# define CMD_2 3
# define F_OUTPUT 4

# define PIPE_READ 0
# define PIPE_WRITE 1

#endif