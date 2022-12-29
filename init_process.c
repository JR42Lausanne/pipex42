/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:27:04 by jlaiti            #+#    #+#             */
/*   Updated: 2022/12/29 14:55:25 by jlaiti           ###   ########.fr       */
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

	pipex.paths = check_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_cmd(pipex, fd_in, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_cmd(pipex, fd_out, argv, envp);
}
