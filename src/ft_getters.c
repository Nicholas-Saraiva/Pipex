/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:48:18 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/08 18:17:06 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void get_fd_file(int fd_file[2], char *read_file, char *write_file)
{
	fd_file[0] = open(read_file, O_RDONLY);
	fd_file[1] = open(write_file, O_WRONLY | O_CREAT | O_TRUNC, 0671);
}

char *get_shell(char **env)
{
	char **str;
	char *shell;
	int i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "SHELL=", 6) == 0)
			break;
	}
	str = ft_split(*env, '/');
	i = -1;
	while (str[++i])
		;
	shell = ft_strdup(str[i - 1]);
	ft_free_all(str);
	return (shell);
}

char **get_paths(char **env)
{
	char **paths;
	char **paths2;
	int i;
	i = -1;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break;
	paths = ft_split(env[i], '=');
	paths2 = ft_split(paths[1], ':');
	ft_free_all(paths);
	return (paths2);
}

static int is_space(unsigned char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

char **get_command(char *s)
{
	size_t i = 0;
	int in_quote = 0;
	char qchar = 0;
	int count = 0;

	if (!s)
		return NULL;

	while (s[i])
	{
		while (s[i] && is_space((unsigned char)s[i]))
			i++;
		if (!s[i])
			break;
		count++;
		while (s[i])
		{
			if (!in_quote && is_space((unsigned char)s[i]))
				break;
			if ((s[i] == '\'' || s[i] == '"'))
			{
				if (!in_quote)
				{
					in_quote = !in_quote;
					qchar = s[i];
				}
				else if (qchar == s[i])
				{
					in_quote = !in_quote;
					qchar = 0;
				}
				i++;
				continue;
			}
			i++;
		}
	}
	if (in_quote)
		return ft_split(s, ' ');

	/* ---- allocate argv ---- */
	char **argv = (char **)malloc((count + 1) * sizeof(char *));
	if (!argv)
		return NULL;

	/* ---- PASS 2: fill argv ---- */
	i = 0;
	int idx = 0;
	while (s[i])
	{
		while (s[i] && is_space((unsigned char)s[i]))
			i++;
		if (!s[i])
			break;

		/* size next word */
		size_t j = i;
		int len = 0;
		in_quote = 0;
		qchar = 0;
		while (s[j])
		{
			if (!in_quote && is_space((unsigned char)s[j]))
				break;
			if ((s[j] == '\'' || s[j] == '"'))
			{
				if (!in_quote)
				{
					in_quote = 1;
					qchar = s[j];
				}
				else if (qchar == s[j])
				{
					in_quote = 0;
					qchar = 0;
				}
				j++;
				continue;
			}
			if (s[j] == '\\' && (in_quote && qchar == '\''))
				len++;
			j++;
			len++;
		}

		char *arg = (char *)malloc(len + 1);
		if (!arg)
		{
			ft_free_all(argv);
			return NULL;
		}

		/* copy token content */
		size_t k = 0;
		in_quote = 0;
		qchar = 0;
		while (i < j)
		{
			if ((s[i] == '\'' || s[i] == '"'))
			{
				if (!in_quote)
				{
					in_quote = 1;
					qchar = s[i];
					i++;
					continue;
				}
				else if (qchar == s[i])
				{
					in_quote = 0;
					qchar = 0;
					i++;
					continue;
				}
			}
			else if (s[i] == '\\' && (in_quote && qchar == '\''))
			{
				arg[k++] = s[i];
				arg[k++] = s[i++];
				continue;
			}
			arg[k++] = s[i++];
		}
		arg[k] = '\0';
		argv[idx++] = arg;
	}
	argv[idx] = NULL;
	return argv;
}

char *get_command_path(char *arg, char **env)
{
	int i;
	char *tmp;
	char *path;
	char **paths;

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