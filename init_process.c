/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:27:04 by jlaiti            #+#    #+#             */
/*   Updated: 2022/12/31 15:10:24 by jlaiti           ###   ########.fr       */
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

void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	printf("step1\n");
}

void	init_process(int fd_in, int fd_out, char *argv[], char *envp[])
{
	t_pipex	pipex;

	pipex.paths = check_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	printf("fork1\n");
	if (pipex.pid1 == 0)
	{
		printf("fork1child\n");
		first_cmd(pipex, fd_in, argv, envp);
	}
	pipex.pid2 = fork();
	printf("fork2\n");
	if (pipex.pid2 == 0)
	{
		printf("fork2child\n");
		second_cmd(pipex, fd_out, argv, envp);
	}
	//close(pipex.pipe_fd[0]);
	//close(pipex.pipe_fd[1]);
	close_pipes(&pipex);
	printf("closepipe\n");
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	printf("final\n");
}
