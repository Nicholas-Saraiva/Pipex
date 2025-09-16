/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:50:07 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/16 16:52:55 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_s)
		return (0);
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
	{
		new_s[i] = *s2;
		s2++;
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
