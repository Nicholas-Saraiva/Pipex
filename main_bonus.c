/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:51:08 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/15 16:54:08 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static pid_t	r_fork(char *argv, t_env env,
					int pfd[2], int fd_file[2]);
static pid_t	g_fork(char *argv, t_env env, int fd_out[2], int fd_in[2]);
static int		pid_status(int argc, pid_t *pid_cmds);
static void		closing_pfd(int i, int argc, t_env env, int *fd_file);

int	main(int argc, char *argv[], char *envp[])
{
	t_env	env;
	int		fd_file[2];
	int		i;

	if (argc < 5)
		exit(2);
	fill_var(fd_file, &env, argc, envp);
	get_fd_file(fd_file, argv[1], argv[argc - 1], envp);
	i = -1;
	while (argc - 3 - ++i > 0)
	{
		if (i == 0)
			env.pid[i] = g_fork(argv[i + 2], env, env.pfd[i], fd_file);
		else if (i == argc - 4)
			env.pid[i] = r_fork(argv[i + 2], env, env.pfd[i - 1], fd_file);
		else
			env.pid[i] = g_fork(argv[i + 2], env, env.pfd[i], env.pfd[i - 1]);
		closing_pfd(i, argc, env, fd_file);
	}
	if (env.pfd)
		free_all_int(env.pfd);
	return (pid_status(argc, env.pid));
}

static pid_t	g_fork(char *argv, t_env env, int fd_out[2], int fd_in[2])
{
	char	*cmd_path;
	char	**args;
	pid_t	pid;

	if (!*argv)
		return (-1);
	if (!init_pid(&pid))
		free_exit(args, cmd_path, 1, env);
	if (pid == 0)
	{
		args = get_command(argv);
		cmd_path = get_command_path(args[0], env.envp);
		if (!*argv || !cmd_path)
			cmd_not_found_bonus(args, env, args[0]);
		if (dup2(fd_in[0], STDIN_FILENO) == -1)
			free_exit(args, cmd_path, 1, env);
		if (dup2(fd_out[1], STDOUT_FILENO) == -1)
			free_exit(args, cmd_path, 1, env);
		closing_fds(fd_out, fd_in);
		if (execve(cmd_path, args, env.envp) == -1)
			free_exit(args, cmd_path, 1, env);
	}
	return (pid);
}

static pid_t	r_fork(char *argv, t_env env, int pfd[2], int fd_file[2])
{
	char	*cmd_path;
	char	**args;
	pid_t	pid;

	if (!*argv)
		return (-1);
	if (!init_pid(&pid))
		free_exit(args, cmd_path, 1, env);
	if (pid == 0)
	{
		args = get_command(argv);
		cmd_path = get_command_path(args[0], env.envp);
		if (!cmd_path)
			cmd_not_found_bonus(args, env, args[0]);
		if (dup2(fd_file[1], STDOUT_FILENO) == -1)
			free_exit(args, cmd_path, 1, env);
		if (dup2(pfd[0], STDIN_FILENO) == -1)
			free_exit(args, cmd_path, 1, env);
		closing_fds(pfd, fd_file);
		if (execve(cmd_path, args, env.envp) == -1)
			free_exit(args, cmd_path, 1, env);
	}
	return (pid);
}

static void	closing_pfd(int i, int argc, t_env env, int fd_file[2])
{
	if (i != argc - 4)
		close(env.pfd[i][1]);
	if (i == 0)
		close(fd_file[0]);
	else if (i == argc - 4)
	{
		close(env.pfd[i - 1][0]);
		close(fd_file[1]);
	}
	else
		close(env.pfd[i - 1][0]);
}

static int	pid_status(int argc, pid_t *pid_cmds)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	while (++i < argc - 3)
		waitpid(pid_cmds[i], &status, 0);
	free(pid_cmds);
	return (WEXITSTATUS(status));
}
