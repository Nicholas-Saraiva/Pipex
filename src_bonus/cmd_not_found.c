/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_not_found.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:59:13 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/17 21:59:14 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cmd_not_found_bonus(char **args, t_env *env, char *cmd)
{
	char	*shell;

	shell = get_shell(env->envp);
	ft_putstr_fd(shell, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n\0", 2);
	if (shell)
		free(shell);
	if (args)
		ft_free_all(args);
	if (env->pfd)
		free_all_int(env->pfd);
	if (env->pid)
		free(env->pid);
	exit(127);
}
