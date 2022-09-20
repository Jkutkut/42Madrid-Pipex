/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:33:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/09/20 11:05:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTS_H
# define PIPEX_STRUCTS_H

# include "pipex.h"

/**
 * @struct t_pipex
 * @brief Struct to hold all the information of the pipex program.
 */
typedef struct s_pipex
{
	/**
	 * @brief Fd of the input file.
	 */
	int		f_input;
	/**
	 * @brief Fd of the output file.
	 */
	int		f_output;
	/**
	 * @brief Array with the cmds (argv)
	 */
	char	**cmds;
	/**
	 * Enviroment variable given by the main.
	 */
	char	**envp;
	/**
	 * @brief Array with the path array.
	 * Result of processing envp
	 */
	char	**env_paths;
	/**
	 * @brief Number of cmds to execute.
	 */
	int		cmd_count;
	/**
	 * @brief Index of the current cmd.
	 */
	int		cmd_idx;
	/**
	 * @brief Array to store all the fds of the pipes.
	 * If index is even, it's the read fd, if odd, it's the write fd.
	 */
	int		*fds;
	/**
	 * @brief Command to execute as an array.
	 * Defined at each process.
	 * Result of spliting the string by spaces.
	 */
	char	**cmd_args;
	/**
	 * @brief Command with the path.
	 */
	char	*cmd_full;
	/**
	 * @brief 0 if here_doc is not present, 1 if it is.
	 */
	int		heredoc;
	/**
	 * @brief Process ids of the processes.
	 */
	int		*pid;
}				t_pipex;

/**
 * @struct t_pipex
 * @brief Struct to hold all the information of the pipex program.
 */
/*
typedef struct s_pipex
{
	int		f_input;
	int		f_output;
	char	**cmds;
	char	**envp;
	char	**env_paths;
	int		cmd_count;
	int		cmd_idx;
	int		*fds;
	char	**cmd_args;
	char	*cmd_full;
	int		heredoc;
	int		*pid;
}				t_pipex;
*/
#endif
