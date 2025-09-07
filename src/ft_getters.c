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

void get_fd_file(int fd_file[2], char *read_file, char *write_file)
{
    fd_file[0] = open(read_file, O_RDONLY);
    fd_file[1] = open(write_file, O_WRONLY | O_CREAT | O_TRUNC, 0671);
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
    if (!arg)
        return (0);
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