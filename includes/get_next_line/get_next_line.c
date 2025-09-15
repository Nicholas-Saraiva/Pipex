/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:29:41 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/07/11 21:35:34 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy_gnl(void *dest, const void *src, size_t n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	c_dest = (unsigned char *) dest;
	c_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}

static char	*ft_newline(char *str, char *buff)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
	{
		buff[i] = '\0';
		i++;
	}
	if (!buff[i])
	{
		buff[0] = '\0';
		return (str);
	}
	while (buff[i + j])
		j++;
	ft_memcpy_gnl(buff, buff + i + 1, j);
	return (str);
}

static char	*ft_create_line(int fd, char *buff, char *str)
{
	int	num_bytes;

	num_bytes = 1;
	while (!check_nl(buff) && num_bytes > 0)
	{
		num_bytes = read(fd, buff, BUFFER_SIZE);
		buff[num_bytes] = '\0';
		str = ft_strjoin_gnl(str, buff);
		if (!str)
			return (0);
	}
	if (num_bytes == -1 || (num_bytes == 0 && !*str))
	{
		free(str);
		*buff = 0;
		return (0);
	}
	return (ft_newline(str, buff));
}

char	*get_next_line(int fd, char **str)
{
	static char	buff[BUFFER_SIZE + 1];

	if (fd < 0)
		return (0);
	*str = malloc(sizeof(char));
	if (!(*str))
		return (NULL);
	**str = '\0';
	if (*buff)
		*str = ft_strjoin_gnl(*str, buff);
	if (!(*str))
		return (0);
	*str = ft_create_line(fd, buff, *str);
	if (!(*str))
		return (0);
	return (*str);
}
