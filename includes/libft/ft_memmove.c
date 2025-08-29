/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:07:28 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/16 21:22:29 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;

	if (!dest && !src)
		return (0);
	c_dest = (unsigned char *) dest;
	c_src = (unsigned char *) src;
	if (dest > src)
	{
		while (n--)
			c_dest[n] = c_src[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char a[] = "CafeBoloAr";

	ft_memmove(a+4, a, 5);
	//memmove(NULL, NULL, 4);
	//ft_memcpy(a+4, a, 5);
	puts(a);
}*/
