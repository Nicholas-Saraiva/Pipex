/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd_file_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:57:54 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/23 12:43:34 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h" 

void	get_fd_file_b(char **argv, int argc, t_env *env)
{
	env->fd_file[0] = -1;
	if (!env->here_doc)
	{
		if (access(argv[1], F_OK) != 0)
			message_error(": no such file or directory: ",
				argv[1], env->envp, 1);
		else
		{
			env->fd_file[0] = open(argv[1], O_RDONLY);
			if (env->fd_file[0] == -1)
				message_error(": Permission denied", argv[1], env->envp, 0);
		}
		env->fd_file[1] = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0671);
		if (env->fd_file[1] == -1)
			message_error(": Permission denied", argv[argc - 1], env->envp, 0);
	}
	else
	{
		env->fd_file[1] = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0671);
		if (env->fd_file[1] == -1)
			message_error(": Permission denied", argv[argc - 1], env->envp, 0);
	}
}
