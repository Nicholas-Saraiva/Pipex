/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:51:08 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/08 17:28:34 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t	reciver_fork(char *argv, char **env, int pfd[2], int fd_file[2]);
static pid_t	giver_fork(char *argv, char **env, int pfd[2], int fd_file[2]);
static void		fill_var(int *fd_file, int *pfd, int *pid_cmds);

int	main(int argc, char *argv[], char *env[])
{
	int	fd_file[2];
	int	pfd[2];
	int	pid_cmds[2];
	int	status;
	
	status = 0;
	fill_var(fd_file, pfd, pid_cmds);
	if (argc < 5)
		return (1);
	get_fd_file(fd_file, argv[1], argv[4]);
	if (pipe(pfd) == -1)
		return (1);
	pid_cmds[0] = giver_fork(argv[2], env, pfd, fd_file);
	pid_cmds[1] = reciver_fork(argv[3], env, pfd, fd_file);
	close(pfd[0]);
	close(pfd[1]);
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

get_shell(char **env)
{
	char 	**str;
	char	*shell;

	while (*env)
	{
		if (ft_strncmp(*env, "SHELL=", 6) == 0)
			break ;
		env++;
	}
	str = ft_split(*env, '/');
	while (*str)
		str++;
	shell = ft_strdup(--str);
	ft_free_all(str);
	return (shell);
}

void	cmd_not_found(char **args, char **env, char *cmd)
{
	ft_putstr_fd("bash : " , 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found" , 2);
	if (cmd)
		free(cmd);
	exit(127);
}

static pid_t giver_fork(char *argv, char **env, int pfd[2], int fd_file[2])
{
	char	*cmd;
	char	**args;
	pid_t	pid;

	if (!init_pid(&pid))
		return (0);
	args = ft_split(argv, ' ');
	cmd = get_command(args[0], env);
	if (pid == 0)
	{
		if (!cmd)
			cmd_not_found(args, env, cmd);
		dup2(pfd[1], STDOUT_FILENO);
		if (dup2(fd_file[0], STDIN_FILENO) == -1)
		{
			if (args)
				ft_free_all(args);
			if (cmd)
				free(cmd);
			ft_error("bash: : No such file or director\n");
		}
		closing_fds(pfd, fd_file);
		execve(cmd, args, env);
	}
	if (args)
		ft_free_all(args);
	if (cmd)
		free(cmd);
	return (pid);
}

static pid_t reciver_fork(char *argv, char **env, int pfd[2], int fd_file[2])
{
	char	*cmd;
	char	**args;
	pid_t	pid;

	if (!init_pid(&pid))
		return (0);
	args = ft_split(argv, ' ');
	cmd = get_command(args[0], env);
	if (pid == 0)
	{
		if (!cmd)
		{
			ft_printf("bash : %s: comand not found", args[0]);
				if (args)
					ft_free_all(args);
				if (cmd)
					free(cmd);
			exit (127);
		}
		if (dup2(fd_file[1], STDOUT_FILENO) == -1)
		{
			perror("dup2 outfile");
			if (args) ft_free_all(args);
				if (cmd) free(cmd);
			exit(1);
		}
		if (dup2(pfd[0], STDIN_FILENO) == -1)
		{
			perror("dup2 pipe");
			if (args) ft_free_all(args);
			if (cmd) free(cmd);
			exit(1);
		}
		closing_fds(pfd, fd_file);
		execve(cmd, args, env);
	}
	if (args)
		ft_free_all(args);
	if (cmd)
		free(cmd);
	return (pid);
}