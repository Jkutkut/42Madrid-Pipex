/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:57:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/09/21 09:20:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>

# include <fcntl.h>
# include <string.h>

# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>

# include "libft.h"
# include "get_next_line.h"

# include "pipex_msg.h"
# include "pipex_structs.h"

# define STDIN 0
# define STDOUT 1
# define STDERROR 2

# define F_INPUT 1
# define CMD_1 2
# define CMD_2 3
# define F_OUTPUT 4

# define PIPE_READ 0
# define PIPE_WRITE 1

// heredoc
# define HEREDOC "heredoc"
# define HEREDOC_FILE ".heredoc.tmp"
# define HEREDOC_SHELL "heredoc> "

/********************************/

/****** Arguments parsing  ******/
// init_pipex.c
void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);

// init_input.c
void	init_input(t_pipex *pipex, char ***argv);

// init_pipes.c
void	init_pipes(t_pipex *pipex);

// init_output.c
void	init_output(t_pipex *pipex, char *path);

// heredoc.c
void	heredoc(char *argv, t_pipex *pipex);

// get_path_array
char	**get_path_array(char **envp);


/****** END LOGIC ******/
// end.c
void	end_error_file(int type, t_pipex *pipex, char *file);
void	free_end(t_pipex *p, int endtype, char *msg);
void	end(int endtype, char *msg);

// free_array.c
void	free_array(char **array);

// void	close_pipe(int *fd);
// void	close_pipes(t_pipex *p);
// char	*get_path(char *cmd_full, char **envp);
// char	*make_path(char *path, char *cmd);
// void	use_pipe(int *fd_in, int *fd_out);

#endif
