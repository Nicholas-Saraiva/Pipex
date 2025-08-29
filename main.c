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

char *get_command(char *arg, char **paths);
char **get_paths(char **env);


int main(int argc, char *argv[], char *env[])
{
    char    *cmd;
    char    **args;
    pid_t   pid;

    if (argc < 2)
        return (1);
    args = ft_split(argv[1], ' ');
    cmd = get_command(args[0], env);
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return (1);
    }
    if (pid == 0)
    {
        if (cmd)
            execve(cmd, args, env);
        else
            ft_printf("bash: %s: command not found", argv[1]);
    }
    else
        waitpid(pid, NULL, 0);
    if (args)
        ft_free_all(args);
    if (cmd)
        free(cmd);
    return (0);
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