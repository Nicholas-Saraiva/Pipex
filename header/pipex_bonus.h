/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:45:08 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/14 16:37:32 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "pipex.h"

typedef struct s_env
{
	char	**envp;
	int		**pfd;
	pid_t	*pid;
}	t_env;

//---Utils_Bonus
int		**creating_pfds(int argc);
void	free_all_int(int **matrix);
void	free_exit(char **args, char *cmd, int to_exit, t_env env);
void	fill_var(int *fd_file, t_env *env, int argc, char **envp);
void	cmd_not_found_bonus(char **args, t_env env, char *cmd);

#endif
