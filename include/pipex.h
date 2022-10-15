/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:57:44 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/10/14 13:02:59 by jre-gonz         ###   ########.fr       */
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
# define HEREDOC "here_doc"
# define HEREDOC_FILE ".heredoc.tmp"
# define HEREDOC_SHELL "heredoc> "

/********************************/

/****** Arguments parsing  ******/
// init_pipex.c
void	ft_init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);

// init_input.c
void	ft_init_input(t_pipex *pipex, int *argc, char ***argv);

// init_pipes.c
void	ft_init_pipes(t_pipex *pipex);

// init_output.c
void	ft_init_output(t_pipex *pipex, char *path);

// heredoc.c
void	ft_heredoc(char *argv, t_pipex *pipex);

// get_path_array
char	**ft_get_path_array(char **envp);


/****** END LOGIC ******/
// end.c
void	ft_end_error_file(int type, t_pipex *pipex, char *file);
int		ft_free_end(t_pipex *p, int endtype, char *msg);
int		ft_end(int endtype, char *msg);

// free_array.c
void	ft_free_array(char **array);

// close_fds.c
void	ft_close_fds(t_pipex *p);

// close_fd.c
void	ft_close_fd(int *fd);

/****** EXECUTION LOGIC ******/
// exe_cmd.c
int		ft_exe_cmd(t_pipex *p);

// use_pipe.c
void	ft_use_pipe(int *fd_in, int *fd_out);

// get_path.c
char	*ft_get_path(char *cmd_full, char **envp);

// make_path.c
char	*ft_make_path(char *path, char *cmd);

#endif
