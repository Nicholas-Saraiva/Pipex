/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:45:08 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/31 17:45:09 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
#define PIPPEX_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "ft_printf.h"
#include "libft.h"

//---Utils
void	ft_free_all(char **str);
void	ft_error(char *str);
void    closing_fds(int fd[2], int fd_file[2]);
int init_pid(pid_t *pid);

//---Getters
int get_fd_file(int fd_file[2], char *read_file, char *write_file);
char **get_paths(char **env);
char *get_command(char *arg, char **env);
#endif