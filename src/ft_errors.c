/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:11:12 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/23 12:01:09 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_not_found(char **args, char **env, char *cmd)
{
	char	*shell;

	shell = get_shell(env);
	ft_putstr_fd(shell, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n\0", 2);
	if (shell)
		free(shell);
	if (args)
		ft_free_all(args);
	exit(127);
}

void	safe_close(int *fd)
{
	if (*fd != -1)
	{
		close(*fd);
		*fd = -1;
	}
}

void	closing_fds(int fd[2], int fd_file[2])
{
	safe_close(&fd[1]);
	safe_close(&fd[0]);
	safe_close(&fd_file[1]);
	safe_close(&fd_file[0]);
}
