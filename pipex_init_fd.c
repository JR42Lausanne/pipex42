/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:53:42 by jlaiti            #+#    #+#             */
/*   Updated: 2023/01/03 15:49:38 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_fd_in(char	*argv)
{
	int	init;

	if (access(argv, F_OK) == 0)
		init = open(argv, O_RDONLY);
	else
	{
		perror(argv);
		return (EXIT_FAILURE);
	}
	return (init);
}

int	init_fd_out(char *argv)
{
	int	init;

	init = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (init == -1)
	{
		perror(argv);
		return (EXIT_FAILURE);
	}
	return (init);
}

void	ft_need_args(void)
{
	perror("Need Cmds => ./pipex [File1] [Cmd1] [Cmd2] [File2]\n");
	exit(EXIT_FAILURE);
}
