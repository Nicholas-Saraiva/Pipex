/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:57:33 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/10 13:00:38 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n--)
	{
		str[n] = '\0';
	}
}

/*#include <stdio.h> 
#include <string.h>
int	main(void)
{
	//int	i = 0;
	//char string[] = "";
	//ft_bzero(string, sizeof(string));
	//i = sizeof(string);
	//while (i--)
	//	if (string[i] != '\0')
	//		printf("FAIL");
	//printf("THE END");	
	//bzero(NULL, 20);
	//ft_bzero(NULL, 20);
	
	char string[] = "adsa";
	bzero(string, 20);
}*/
