/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:24:41 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/29 18:25:37 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_all(char **str)
{
	int	i;

	i = -1;
	if (!(*str))
		return ;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	init_pid(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		return (0);
	}
	return (1);
}

int	check_in_quote(char s, int *in_quote, char *qchar)
{
	if ((s == '\'' || s == '"'))
	{
		if (*in_quote == 0)
		{
			*in_quote = 1;
			*qchar = s;
		}
		else if (*qchar == s)
		{
			*in_quote = 0;
			*qchar = 0;
		}
		return (1);
	}
	return (0);
}

int	is_space(unsigned char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c
		== '\r' || c == '\v' || c == '\f');
}
