/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:48:18 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/31 17:48:20 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int get_fd_file(char *file, char option)
{
    if (option = 'g')
        return (open(file, O_RDONLY));
    else 
    {
        if (access(file, F_OK) == 0  && access(file, W_OK) != 0)
            ft_printf("Could not open write file\n");
        else if (access(file, W_OK) == 0 || access(file, F_OK) != 0)
            return (open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644));
    }
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