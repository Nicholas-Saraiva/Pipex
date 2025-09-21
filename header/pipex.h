/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:45:08 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/16 16:39:12 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

//---Utils
void	ft_free_all(char **str);
int		init_pid(pid_t *pid);
int		check_in_quote(char s, int *in_quote, char *qchar);
int		is_space(unsigned char c);
void	message_error(char	*str, char *file, char **env, int type);

//---Getters
void	get_fd_file(int fd_file[2], char *read_file,
			char *write_file, char **env);
char	**get_paths(char **env);
char	**get_command(char *argv);
char	*get_command_path(char **arg, char **env);
char	*get_shell(char **env);

//---Errors
void	cmd_not_found(char **args, char **env, char *cmd);
void	safe_close(int *fd);
void	closing_fds(int fd[2], int fd_file[2]);

//---CountWords
int		count_words(char *s);

#endif
