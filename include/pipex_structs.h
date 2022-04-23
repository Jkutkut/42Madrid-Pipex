/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:33:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/23 13:32:31 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTS_H
# define PIPEX_STRUCTS_H

#include "pipex.h"

typedef struct	pipex_s
{
	int		f_input;
	int		f_output;
	char	**cmds;
	char	**env_paths;
	int  	cmd_count;
	int		fd_idx;
	int		*fds;
	char	*cmd;
	char	**cmd_args;
	pid_t	pid;

	int		here_doc;
	// TODO
}				pipex_t;

#endif