/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:27:04 by jlaiti            #+#    #+#             */
/*   Updated: 2023/01/02 15:32:58 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
	{
		i++;
	}
	return (envp[i] + 5);
}

void	close_pipes(t_pipex *pipex, int fd_in, int fd_out)
{
	close(pipex->pipe_fd[1]);
	close(pipex->pipe_fd[0]);
	close(fd_in);
	close(fd_out);
}

void	init_process(int fd_in, int fd_out, char *argv[], char *envp[])
{
	t_pipex	pipex;

	pipex.paths = check_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipe(pipex.pipe_fd);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
	{
		first_cmd(pipex, fd_in, argv, envp);
	}
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
	{
		second_cmd(pipex, fd_out, argv, envp);
	}
	close_pipes(&pipex, fd_in, fd_out);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}
