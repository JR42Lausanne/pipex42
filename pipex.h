/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:57:16 by jlaiti            #+#    #+#             */
/*   Updated: 2022/12/29 15:12:31 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdlib.h>

typedef struct s_pipex
{
	char	*paths;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
}		t_pipex;

int	init_fd_in(char	*arg);
int	init_fd_out(char *arg);
void	ft_need_args(void);
char	*check_path(char *envp[]);
char	*get_cmd(char **paths, char *cmd);
void	init_process(int fd_in, int fd_out, char *argv[], char *envp[]);
void	first_cmd(t_pipex pipex, int fd_in, char *argv[], char *envp[]);
void	second_cmd(t_pipex pipex, int fd_out, char *argv[], char *encp[]);

#endif
