/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:44:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/09/20 18:35:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Ends the execution of the program when there's a problem with a file.
 * 
 * @param endtype Type of end (0: normal, 1: error)
 * @param msg Message to display if error.
 */
void	end_error_file(int type, t_pipex *pipex, char *file)
{
	char	error_msg[1024];

	if (type == 0)
		ft_memmove(error_msg, "No such file or directory: ", 28);
	else
		ft_memmove(error_msg, "Not able to open: ", 19);
	ft_strlcat(error_msg, file, ft_strlen(error_msg) + ft_strlen(file) + 1);
	free_end(pipex, 1, error_msg);
}

/**
 * @brief Frees all the alocated memory and ends the process with the given
 * endtype and message.
 * 
 * If message is NULL, the message is omitted.
 * 
 * @param p The pipex struct used.
 * @param endtype The exit code.
 * @param msg The message to print if given.
 */
void	free_end(t_pipex *p, int endtype, char *msg)
{
	if (p->f_input != -1)
		close(p->f_input);
	if (p->f_output != -1)
		close(p->f_output);
	if (p->env_paths)
		free_array(p->env_paths);
	if (p->fds)
	{
		// close_pipes(p); // TODO
		free(p->fds);
	}
	if (p->pid)
		free(p->pid);
	if (p->heredoc)
		unlink(HEREDOC_FILE);
	end(endtype, msg);
}

/**
 * @brief Ends the execution of the program
 * 
 * @param endtype Type of end (0: normal, 1: error)
 * @param msg Message to display if error.
 */
void	end(int endtype, char *msg)
{
	if (msg != NULL)
	{
		ft_putstr_fd("Error:\n  ", STDERROR);
		ft_putstr_fd(msg, STDERROR);
	}
	exit(endtype);
}
