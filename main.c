/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:51:08 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/29 13:05:20 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int reciver_fork(char *argv, char **env, int fd[2], int fd_file[2]);
static int giver_fork(char *argv, char **env, int fd[2], int fd_file[2]);

int main(int argc, char *argv[], char *env[])
{
    int     fd_file[2];
    int     fd[2];

    if (argc < 4)
        ft_error("It must take 4 arguments, like: ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
    if (pipe(fd) == -1)
        return (1);
    if (!get_fd_file(fd_file, argv[1], argv[4]))
        return (1);
    if (!giver_fork(argv[2], env, fd, fd_file))
        return (1);
    if (!reciver_fork(argv[3], env, fd, fd_file))
        return (1);
    close(fd[0]);
    close(fd[1]);
    waitpid(-1, NULL, 0);
    return (0);
}

static int giver_fork(char *argv, char **env, int fd[2], int fd_file[2])
{
    char    *cmd;
    char    **args;
    pid_t   pid;

    if (!init_pid(&pid))
        return (0);
    args = ft_split(argv, ' ');
    cmd = get_command(args[0], env);
    if (pid == 0)
    {
        dup2(fd_file[0], STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        closing_fds(fd, fd_file);
        if (cmd)
            execve(cmd, args, env);
        else
            ft_printf("bash: %s: command not found", args[0]);
    }
    if (args)
        ft_free_all(args);
    if (cmd)
        free(cmd);
    return (1);
}

static int  reciver_fork(char *argv, char **env, int fd[2], int fd_file[2])
{
    char    *cmd;
    char    **args;
    pid_t   pid;

    if (!init_pid(&pid))
        return (0);
    args = ft_split(argv, ' ');
    cmd = get_command(args[0], env);
    if (pid == 0)
    {
        dup2(fd_file[1], STDOUT_FILENO);
        dup2(fd[0], STDIN_FILENO);
        closing_fds(fd, fd_file);
        if (cmd)
            execve(cmd, args, env);
        else
            ft_printf("bash : %s: command not found", args[0]);
    }
    if (args)
        ft_free_all(args);
    if (cmd)
        free(cmd);
    return (1);
}