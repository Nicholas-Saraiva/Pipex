/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:11:12 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/08 18:08:26 by nsaraiva         ###   ########.fr       */
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
