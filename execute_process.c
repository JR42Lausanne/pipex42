/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:58:34 by jlaiti            #+#    #+#             */
/*   Updated: 2022/12/30 17:02:09 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	first_cmd(t_pipex pipex, int fd_in, char *argv[], char *envp[])
{
	dup2(pipex.pipe_fd[1], 1);
	close(pipex.pipe_fd[0]);
	dup2(fd_in, 0);
	printf("child11\n");
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{	
		exit(1);
	}
	printf("child12\n");
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_cmd(t_pipex pipex, int fd_out, char *argv[], char *envp[])
{
	printf("child20\n");
	dup2(pipex.pipe_fd[0], 0);
	printf("child21\n");
	close(pipex.pipe_fd[0]);
	printf("child22\n");
	dup2(fd_out, 1);
	printf("child23\n");
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		exit(1);
	}
	printf("child24\n");
	execve(pipex.cmd, pipex.cmd_args, envp);
}
