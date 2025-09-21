/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:51:08 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/15 16:53:47 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t	reciver_fork(char *argv, char **env,
					int pfd[2], int fd_file[2]);
static pid_t	giver_fork(char *argv, char **env, int pfd[2], int fd_file[2]);
static void		fill_var(int *fd_file, int *pfd, int *pid_cmds);
static void		free_exit(char **args, char *cmd, int to_exit);

int	main(int argc, char *argv[], char *env[])
{
	int	fd_file[2];
	int	pfd[2];
	int	pid_cmds[2];
	int	status;

	status = 0;
	if (argc < 5 || !(*env))
		return (2);
	fill_var(fd_file, pfd, pid_cmds);
	get_fd_file(fd_file, argv[1], argv[4], env);
	if (pipe(pfd) == -1)
		return (1);
	pid_cmds[0] = giver_fork(argv[2], env, pfd, fd_file);
	pid_cmds[1] = reciver_fork(argv[3], env, pfd, fd_file);
	closing_fds(pfd, fd_file);
	waitpid(pid_cmds[0], NULL, 0);
	waitpid(pid_cmds[1], &status, 0);
	return (WEXITSTATUS(status));
}

static void	fill_var(int *fd_file, int *pfd, int *pid_cmds)
{
	pid_cmds[0] = 0;
	pid_cmds[1] = 0;
	fd_file[0] = 0;
	fd_file[1] = 0;
	pfd[0] = 0;
	pfd[1] = 0;
}

static pid_t	giver_fork(char *argv, char **env, int pfd[2], int fd_file[2])
{
	char	*cmd;
	char	**args;
	pid_t	pid;

	if (!*argv)
		return (-1);
	if (!init_pid(&pid))
		return (0);
	args = get_command(argv);
	cmd = get_command_path(args[0], env);	
	if (pid == 0)
	{
		if (!cmd)
			cmd_not_found(args, env, args[0]);
		dup2(pfd[1], STDOUT_FILENO);
		if (dup2(fd_file[0], STDIN_FILENO) == -1)
			free_exit(args, cmd, 1);
		closing_fds(pfd, fd_file);
		if (execve(cmd, args, env) == -1)
			free_exit(args, cmd, 1);
	}
	return (free_exit(args, cmd, 0), pid);
}

static pid_t	reciver_fork(char *argv, char **env, int pfd[2], int fd_file[2])
{
	char	*cmd;
	char	**args;
	pid_t	pid;

	if (!*argv)
		return (-1);
	if (!init_pid(&pid))
		return (0);
	args = get_command(argv);
	cmd = get_command_path(args[0], env);
	if (pid == 0)
	{
		if (!cmd)
			cmd_not_found(args, env, args[0]);
		if (dup2(fd_file[1], STDOUT_FILENO) == -1)
			free_exit(args, cmd, 1);
		if (dup2(pfd[0], STDIN_FILENO) == -1)
			free_exit(args, cmd, 1);
		closing_fds(pfd, fd_file);
		if (execve(cmd, args, env) == -1)
			free_exit(args, cmd, 1);
	}
	return (free_exit(args, cmd, 0), pid);
}

static void	free_exit(char **args, char *cmd, int to_exit)
{
	if (args)
		ft_free_all(args);
	if (cmd)
		free(cmd);
	if (to_exit)
		exit(1);
}
