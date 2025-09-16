/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:45:08 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/16 17:24:07 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "pipex.h"

typedef struct s_env
{
	char	**envp;
	int		**pfd;
	int		n_cmds;
	int		here_doc;
	pid_t	*pid;
}	t_env;

//---Utils_Bonus
int		**creating_pfds(int argc);
void	free_all_int(int **matrix);
void	free_exit(char **args, char *cmd, int to_exit, t_env *env);
void	fill_var(int *fd_file, t_env *env, int argc, char **envp);
void	cmd_not_found_bonus(char **args, t_env *env, char *cmd);
void	get_fd_file_b(int fd_file[2], char **argv, int argc, t_env *env);

int		check_here_doc(t_env *env, char **argv, int *i);
void	print_here_doc(t_env env);
void	here_doc(char *limiter, t_env *env, int fd_out[2]);

void	safe_close(int *fd);

#endif
