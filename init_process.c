/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:27:04 by jlaiti            #+#    #+#             */
/*   Updated: 2022/12/30 16:21:43 by jlaiti           ###   ########.fr       */
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

void	init_process(int fd_in, int fd_out, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;

	i = 0;
	pipex.paths = check_path(envp);
	printf("%s\n", pipex.paths);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	/*while (pipex.cmd_paths)
	{
		printf("%s\n", pipex.cmd_paths[i]);
		i++;
	}*/
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_cmd(pipex, fd_in, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_cmd(pipex, fd_out, argv, envp);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}
