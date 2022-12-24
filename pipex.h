/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:57:16 by jlaiti            #+#    #+#             */
/*   Updated: 2022/12/24 15:17:02 by jlaiti           ###   ########.fr       */
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
	char	**cmd;
	char	*cmd_args;
}		t_pipex;

int		init_fd_in(char	*arg);
int		init_fd_out(char *arg);
char	*check_path(char *envp[]);
void	ft_execute(char *cmd, char *envp[]);
void	split_process(char *cmd, char *envp[]);
void	ft_need_args(void);

#endif
