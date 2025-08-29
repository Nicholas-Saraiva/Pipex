/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:06:31 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/17 10:16:39 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char	*src)
{
	char	*duplicated;
	char	*start;

	duplicated = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!duplicated)
		return (0);
	start = duplicated;
	while (*src)
	{
		*duplicated = *src;
		duplicated++;
		src++;
	}
	*duplicated = '\0';
	return (start);
}
