/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:47:56 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/01 14:23:50 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_TOOLS_H
# define PIPEX_TOOLS_H

# include "pipex.h"

# define HEREDOC_FILE ".heredoc.tmp"
# define HEREDOC "heredoc> "

void	close_pipe(int *fd);
void	close_pipes(t_pipex *p);
void	end_error_file(int type, t_pipex *pipex, char *file);
void	end(int endtype, char *msg);
void	free_array(char **array);
void	free_end(t_pipex *p, int endtype, char *msg);
char	**get_path_array(char **envp);
char	*get_path(char *cmd_full, char **envp);
void	heredoc(char *argv, t_pipex *pipex);
void	init_input(t_pipex *pipex, char ***argv);
void	init_output(t_pipex *pipex, char *path);
void	init_pipes(t_pipex *pipex);
void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
char	*make_path(char *path, char *cmd);
void	use_pipe(int *fd_in, int *fd_out);

#endif
