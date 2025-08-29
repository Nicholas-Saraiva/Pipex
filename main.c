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

int check_path(char *arg, char **paths);
char **get_paths(char **env);


int main(int argc, char *argv[], char *env[])
{
    if (argc < 2)
        return (1);
    if (check_path(argv[1], env))
            ft_printf("%s --- is a valid command", argv[1]);
    else
        ft_printf("bash: %s: command not found", argv[1]);
    return (0);
}

int check_path(char *arg, char **env)
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
            free(path);
            ft_free_all(paths);
            return (1);
        }
        free(path);
    }
    ft_free_all(paths);
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
}