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

static pid_t reciver_fork(char *argv, char **env, int fd[2], int fd_file[2]);
static pid_t giver_fork(char *argv, char **env, int fd[2], int fd_file[2]);

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
    fd[0] = 0;
    fd[1] = 0;
    if (argc < 5)
        ft_error("It must take 4 arguments, like: ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
    get_fd_file(fd_file, argv[1], argv[4]);
    if (pipe(fd) == -1)
        return (1);
    pid_giver = giver_fork(argv[2], env, fd, fd_file);
    pid_reciver = reciver_fork(argv[3], env, fd, fd_file);
    close(fd[0]);
    close(fd[1]);
    waitpid(pid_giver, NULL, 0);              
    waitpid(pid_reciver, &status, 0);
    return (WEXITSTATUS(status));
}

static pid_t giver_fork(char *argv, char **env, int fd[2], int fd_file[2])
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
        if (!cmd)
        {
            ft_printf("bash : %s: command not found", args[0]);
            ft_free_all(args);
            if (cmd)
                free(cmd);
            exit(127);
        }
        dup2(fd[1], STDOUT_FILENO);
        if (dup2(fd_file[0], STDIN_FILENO) == -1)
        {
            if (args)
                ft_free_all(args);
            if (cmd)
                free(cmd);
            ft_error("bash: : No such file or director\n");
        }
        closing_fds(fd, fd_file);
        execve(cmd, args, env);
    }
    if (args)
        ft_free_all(args);
    if (cmd)
        free(cmd);
    return (pid);
}

static pid_t reciver_fork(char *argv, char **env, int fd[2], int fd_file[2])
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
        if (dup2(fd[0], STDIN_FILENO) == -1)
        {
            perror("dup2 pipe");
            if (args) ft_free_all(args);
            if (cmd) free(cmd);
            exit(1);
        }
        closing_fds(fd, fd_file);
        execve(cmd, args, env);
    }
    if (args)
        ft_free_all(args);
    if (cmd)
        free(cmd);
    return (pid);
}