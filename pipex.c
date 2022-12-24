/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:52:33 by jlaiti            #+#    #+#             */
/*   Updated: 2022/12/24 15:29:24 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd_in;
	int		fd_out;
	pid_t		pid1;
	pid_t		pid2;
	t_pipex		pipex;

	if (argc == 5)
	{
		fd_in = init_fd_in(argv[1]);
		fd_out = init_fd_out(argv[argc - 1]);
		init_process(pipex, envp);
	}
	else
		ft_need_args();
	return (0);
}
