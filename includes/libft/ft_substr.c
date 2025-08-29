/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:45:57 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/16 15:48:31 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	i;

	i = 0;
	if (!*s || start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = (size_t) ft_strlen(s) - start;
	sub_string = (char *) malloc((len + 1) * sizeof(char));
	if (!sub_string)
		return (0);
	while (s[start + i] && i < len)
	{
		sub_string[i] = s[start + i];
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}

/*#include <stdio.h>
int	main(void)
{
	char	a[] = "BOm DIa MUNdo eu QueERo CAfFE";
	char	*b = ft_substr(a, 14, 20);
	char	*c = ft_substr("", 0, 0);

	puts(b);
	puts(c);
	free(b);
	free(c);
}*/
