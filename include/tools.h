/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:47:56 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/22 08:35:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "pipex.h"

void	end_error_file(char *file);
void	end(int endtype, char *msg);
char	**get_path_array(char **envp);
char	*get_path(char *cmd_full, char **envp);
void	init_pipex(pipex_t *pipex, int argc, char **argv, char **envp);

#endif