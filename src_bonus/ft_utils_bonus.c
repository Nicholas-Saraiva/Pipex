/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:13:37 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/14 15:13:39 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all_int(int **matrix);

int	**creating_pfds(int argc)
{
	int	i;
	int	**pfd;

	i = -1;
	pfd = ft_calloc(argc - 3, sizeof(int *));
	if (!pfd)
		exit(1);
	while (++i < argc - 4)
	{
		pfd[i] = ft_calloc(2, sizeof(int));
		if (pipe(pfd[i]) == -1)
		{
			free_all_int(pfd);
			exit(EXIT_FAILURE);
		}
	}
	return (pfd);
}

void	fill_var(int *fd_file, t_env *env, int argc, char **envp)
{
	int	i;

	i = -1;
	fd_file[0] = 0;
	fd_file[1] = 0;
	env->pid = ft_calloc(argc - 3, sizeof(pid_t));
	if (!env->pid)
		exit(1);
	env->pfd = creating_pfds(argc);
	env->envp = envp;
}

void	free_all_int(int **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	free_exit(char **args, char *cmd, int to_exit, t_env env)
{
	if (args)
		ft_free_all(args);
	if (cmd)
		free(cmd);
	free_all_int(env.pfd);
	if (env.pid)
		free(env.pid);
	if (to_exit)
		exit(1);
}

void	cmd_not_found_bonus(char **args, t_env env, char *cmd)
{
	char	*shell;

	shell = get_shell(env.envp);
	ft_putstr_fd(shell, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n\0", 2);
	if (shell)
		free(shell);
	if (args)
		ft_free_all(args);
	if (env.pfd)
		free_all_int(env.pfd);
	if (env.pid)
		free(env.pid);
	exit(127);
}
