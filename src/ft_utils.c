/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:24:41 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/29 18:25:37 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_all(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void    closing_fds(int fd[2], int fd_file[2])
{
        close(fd[1]);
        close(fd[0]);
        close(fd_file[1]);
        close(fd_file[0]);
}

int init_pid(pid_t *pid)
{
    *pid = fork();
    if (*pid == -1)
    {
        perror("fork");
        return (0);
    }
    return (1);
}