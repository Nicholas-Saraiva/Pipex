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

int get_fd_file(int fd_file[2], char *read_file, char *write_file)
{
    if (access(read_file, R_OK) != 0)
    {
        ft_printf("bash: %s: No such file or directory", read_file);
        return (0);
    }
    if (access(write_file, R_OK) != 0)
    {
        ft_printf("bash: %s: No such file or directory", write_file);
        return (0);
    }
    fd_file[0] = open(read_file, O_RDONLY);
    if (fd_file[0] == -1)
        ft_error("Could not open read file");
    fd_file[1] = open(write_file, O_WRONLY);
    if (fd_file[1] == -1)
        ft_error("Could not open Write file");
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