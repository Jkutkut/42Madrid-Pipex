/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:33:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/10/25 18:39:10 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTS_H
# define PIPEX_STRUCTS_H

# include "pipex_bonus.h"

/**
 * @struct t_pipex
 * @brief Struct to hold all the information of the pipex program.
 */
typedef struct s_pipex
{
	int		f_input;
	int		f_output;
	char	*cmds[2];
	char	**envp;
	char	**env_paths;
	int		cmd_idx;
	int		fds[2];
	char	**cmd_args;
	char	*cmd_full;
	int		pid[2];
}				t_pipex;
#endif
