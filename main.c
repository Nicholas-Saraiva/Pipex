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
#include <fcntl.h>

char *get_command(char *arg, char **paths);
char **get_paths(char **env);
int init_pid(pid_t *pid);
int    reciver_fork(char *argv, char **env, int fd[2], int fd_file[2]);
int giver_fork(char *argv, char **env, int fd[2], int fd_file[2]);
int get_fd_file(int fd_file[2], char *read_file, char *write_file);

int main(int argc, char *argv[], char *env[])
{
    int     fd_file[2];
    int     fd[2];

    if (pipe(fd) == -1)
        return (1);
    if (argc < 2)
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

int get_fd_file(int fd_file[2], char *read_file, char *write_file)
{
    if (access(read_file, R_OK) != 0 || access(write_file, W_OK) != 0)
        return (0);
    fd_file[0] = open(read_file, O_RDONLY);
    if (fd_file[0] == -1)
        return (0);
    fd_file[1] = open(write_file, O_WRONLY);
    if (fd_file[1] == -1)
        return (0);
    return (1);
}

int giver_fork(char *argv, char **env, int fd[2], int fd_file[2])
{
    char    *cmd;
    char    **args;
    int     new_fd;
    pid_t   pid;

    if (!init_pid(&pid))
        return (0);
    args = ft_split(argv, ' ');
    cmd = get_command(args[0], env);
    if (pid == 0)
    {
        dup2(fd_file[0], STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        close(fd[0]);
        close(fd_file[1]);
        close(fd_file[0]);
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

int    reciver_fork(char *argv, char **env, int fd[2], int fd_file[2])
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
        close(fd[1]);
        close(fd[0]);
        close(fd_file[1]);
        close(fd_file[0]);
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

int init_pid(pid_t *pid)
{
    *pid = fork();
    if (*pid == -1)
    {
        perror("fork");
        return (0);
    }
    return (1);
}

char **get_paths(char **env)
{
    char    **paths;
    
    while (*env)
    {
        if (ft_strncmp(*env, "PATH=", 5) == 0)
            break ;
        env++;
    }
    paths = ft_split(*env, ':');
    return (paths);
}

char *get_command(char *arg, char **env)
{
    int     i;
    char    *tmp;
    char    *path;
    char    **paths;

    i = -1;
    paths = get_paths(env);
    while (paths[++i])
    {
        tmp = ft_strjoin(paths[i], "/");
        path = ft_strjoin(tmp, arg);
        free(tmp);
        if (access(path, X_OK) == 0)
        {
            ft_free_all(paths);
            return (path);
        }
        free(path);
    }
    ft_free_all(paths);
    return (0);
}