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

static pid_t reciver_fork(char *argv, char *file, char **env, int fd[2]);
static pid_t giver_fork(char *argv, char *file, char **env, int fd[2]);

int main(int argc, char *argv[], char *env[])
{
    int     fd_file[2];
    int     fd[2];
    int     pid_giver;
    int     pid_reciver;
    int     status;

    status = 0;
    pid_giver = 0;
    pid_reciver = 0;
    fd_file[0] = 0;
    fd_file[1] = 0;
    if (argc < 4)
        ft_error("It must take 4 arguments, like: ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
    if (pipe(fd) == -1)
        return (1);
    if (fd_file[0] != 0)
        pid_giver = giver_fork(argv[2], argv[1], env, fd);
    if (fd_file[1] != 0)
        pid_reciver = reciver_fork(argv[3], argv[4], env, fd);
    close(fd[0]);
    close(fd[1]);
    waitpid(pid_reciver, &status, 0);
    while (wait(NULL) != -1);
    return (WEXITSTATUS(status));
}

static pid_t giver_fork(char *argv, char *file, char **env, int fd[2])
{
    char    *cmd;
    char    **args;
    int     fd_file;
    pid_t   pid;

    if (!init_pid(&pid))
        return (0);
    args = ft_split(argv, ' ');
    cmd = get_command(args[0], env);
    if (pid == 0)
    {
        fd_file = get_fd_file(file, 'g');
        dup2(fd_file, STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        closing_fds(fd, fd_file);
        if (!cmd || execve(cmd, args, env) == -1)
        {
            ft_printf("bash : %s: command not found", args[0]);
            if (args)
                ft_free_all(args);
            if (cmd)
                free(cmd);
            return (0);
        }
    }
    if (args)
        ft_free_all(args);
    if (cmd)
        free(cmd);
    return (pid);
}

static pid_t reciver_fork(char *argv, char *file, char **env, int fd[2])
{
    char    *cmd;
    char    **args;
    int     fd_file;
    pid_t   pid;

    if (!init_pid(&pid))
        return (0);
    args = ft_split(argv, ' ');
    cmd = get_command(args[0], env);
    if (pid == 0)
    {
        fd_file = get_fd_file(file, 'r');
        dup2(fd_file, STDOUT_FILENO);
        dup2(fd[0], STDIN_FILENO);
        closing_fds(fd, fd_file);
        if (!cmd || execve(cmd, args, env) == -1)
        {
            ft_printf("bash : %s: comand not found", args[0]);
            if (args)
                ft_free_all(args);
            if (cmd)
                free(cmd);
            return (0);
        }
    }
    if (args)
        ft_free_all(args);
    if (cmd)
        free(cmd);
    return (pid);
}