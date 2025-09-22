/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closing_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:30:33 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/22 15:35:21 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_closing_all(int **pfd)
{
	int	i;

	i = -1;
	while (pfd && pfd[++i])
	{
		safe_close(&pfd[i][0]);
		safe_close(&pfd[i][1]);
	}
}
