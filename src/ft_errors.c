/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:11:12 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/08 17:23:27 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_not_found(char **args, char **env, char *cmd)
{
	ft_putstr_fd("bash : " , 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found" , 2);
	if (cmd)
		free(cmd);
	exit(127);
}
