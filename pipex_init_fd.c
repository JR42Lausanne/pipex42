/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:53:42 by jlaiti            #+#    #+#             */
/*   Updated: 2022/12/24 14:53:54 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_fd_in(char	*arg)
{
	int	init;

	if (access(arg, F_OK) == 0)
		init = open(arg, O_RDONLY);
	else
	{
		perror(arg);
		return (EXIT_FAILURE);
	}
	return (init);
}

int	init_fd_out(char *arg)
{
	int	init;

	init = open(arg, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (init == -1)
	{
		perror(arg);
		return (EXIT_FAILURE);
	}
	return (init);
}

void	ft_need_args(void)
{
	ft_printf("Need Cmds => ./pipex [File1] [Cmd1] [Cmd2] [File2]\n");
	exit(EXIT_FAILURE);
}
