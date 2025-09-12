/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:56:07 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/09 21:56:08 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_var(int *i, int *in_quote, char *qchar, int *count);

int	count_words(char *s)
{
	int		i;
	int		in_quote;
	int		count;
	char	qchar;

	init_var(&i, &in_quote, &qchar, &count);
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i])
		{
			if (!in_quote && is_space(s[i]))
				break ;
			check_in_quote(s[i], &in_quote, &qchar);
			i++;
		}
	}
	return (count);
}

static void	init_var(int *i, int *in_quote, char *qchar, int *count)
{
	*i = 0;
	*in_quote = 0;
	*qchar = 0;
	*count = 0;
}
