/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:33:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/21 09:50:00 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTS_H
# define PIPEX_STRUCTS_H

#include "pipex.h"

typedef struct	pipex_s
{
	// char	*f_input;
	// char	*f_output;
	int		f_input;
	int		f_output;
	char	*env_path;
	char	**env_paths;
	int		fds[2];
	char	*cmd;
	char	**cmd_args;
	pid_t	pid;

	// int		here_doc;
	// TODO
}				pipex_t;

#endif