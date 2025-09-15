/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:48:35 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/07/11 21:25:52 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] && s[length] != '\n')
		length++;
	if (s[length] == '\n')
		length++;
	return (length);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_s)
		return (free(s1), NULL);
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		new_s[i] = *s2;
		s2++;
		i++;
		if (new_s[i - 1] == '\n')
			break ;
	}
	new_s[i] = '\0';
	free(s1);
	return (new_s);
}
