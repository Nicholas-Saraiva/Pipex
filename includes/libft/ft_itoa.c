/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:53:29 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/16 16:11:25 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_divide(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		size;
	int		sign;
	char	*str_n;

	sign = 1;
	size = ft_divide(n);
	str_n = (char *) malloc((size + 1) * sizeof(char));
	if (!str_n)
		return (0);
	str_n[size] = '\0';
	if (n < 0)
	{
		sign = -1;
		str_n[0] = '-';
	}
	if (n == 0)
		str_n[0] = '0';
	while (n != 0)
	{
		str_n[--size] = '0' + (n % 10) * sign;
		n /= 10;
	}
	return (str_n);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(632));
	printf("%s\n", ft_itoa(-213));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
}*/
