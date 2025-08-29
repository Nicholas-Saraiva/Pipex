/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:46:30 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/16 14:46:41 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	s_s;

	i = 0;
	s_s = ft_strlen(s);
	while (i <= s_s)
	{
		if (s[s_s - i] == (unsigned char) c)
			return ((char *)(s + s_s - i));
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	char	str[] = "ok ache ! isso Aqui ! ou nao";
	
	puts(ft_strrchr(str, '!'));
}*/
