/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:18:44 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/17 22:18:45 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*self_strjoin(char **s1, char *s2)
{
	int		i;
	char	*new_s;

	new_s = NULL;
	i = 0;
	new_s = (char *) malloc((ft_strlen(*s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (!new_s)
		return (0);
	while (*s1 && (*s1)[i])
	{
		new_s[i] = (*s1)[i];
		i++;
	}
	while (s2 && *s2)
	{
		new_s[i++] = *s2;
		s2++;
	}
	if (*s1)
		free(*s1);
	new_s[i] = '\0';
	return (new_s);
}
