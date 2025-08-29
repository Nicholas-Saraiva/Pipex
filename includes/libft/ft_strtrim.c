/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:03:00 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/17 10:41:16 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compare(char s1, char const *ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		if (s1 == ret[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_count(char const *s1, char const *set
		, size_t s_s1, size_t counter[2])
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_compare(s1[i], set))
	{
		counter[0]++;
		i++;
	}
	i = 0;
	while (i != s_s1 && counter[0] != s_s1 && ft_compare(s1[s_s1 - i - 1], set))
	{
		counter[1]++;
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_s1;
	size_t	count[2];
	size_t	i;
	char	*str;

	i = 0;
	s_s1 = ft_strlen(s1);
	count[0] = 0;
	count[1] = 0;
	ft_count(s1, set, s_s1, count);
	str = malloc(s_s1 - (count[0] + count[1]) + 1);
	if (!str)
		return (0);
	while (s1[count[0] + i]
		&& count[0] + i < s_s1 - count[1])
	{
		str[i] = s1[count[0] + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
int main (void)
{
	//char *s = " \n\n\nOk I ThinK \n nOw i understood!\n\t or not?:/\n   \n";
 	char *res = ft_strtrim(s, " \n\t");
	//char *s = "           ";
	//char *res = ft_strtrim(s, " ");
	puts(res);
	free(res);
}*/
