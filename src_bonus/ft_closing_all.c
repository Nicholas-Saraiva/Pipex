/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closing_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:30:33 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/23 12:21:24 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_closing_all(t_env *env)
{
	int	i;

	i = -1;
	while (env->pfd && env->pfd[++i])
	{
		safe_close(&env->pfd[i][0]);
		safe_close(&env->pfd[i][1]);
	}
	safe_close(&env->fd_file[0]);
	safe_close(&env->fd_file[1]);
}
