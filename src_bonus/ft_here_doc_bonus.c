/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:26:07 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/18 14:30:54 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*strjoin(char **s1, char *s2);

int	check_here_doc(t_env *env, char **argv, int *i)
{
	if (ft_strncmp(argv[1], "here_doc", sizeof(argv[1])) == 0)
	{
		env->here_doc = 1;
		*i = 0;
		here_doc(argv[2], env, env->pfd[0]);
		return (1);
	}
	*i = -1;
	env->here_doc = 0;
	return (0);
}

void	print_here_doc(t_env env)
{
	int	i;

	i = -1;
	while (++i < env.n_cmds - 2)
		ft_printf("pipe ");
	ft_printf("heredock> ");
}

void	here_doc(char *limiter, t_env *env, int fd_out[2])
{
	char	*str;
	char	*line;

	str = NULL;
	line = NULL;
	print_here_doc(*env);
	while (get_next_line(0, &str))
	{
		if (ft_strncmp(str, limiter, ft_strlen(str) - 1) == 0)
		{
			free(str);
			break ;
		}
		line = strjoin(&line, str);
		if (!line)
			free_exit(NULL, str, 1, env);
		free(str);
		print_here_doc(*env);
	}
	ft_putstr_fd(line, env->pfd[0][1]);
	if (line)
		free(line);
	safe_close(&env->pfd[0][1]);
}

static char	*strjoin(char **s1, char *s2)
{
	int		i;
	char	*new_s;

	new_s = NULL;
	i = 0;
	new_s = (char *) malloc((ft_strlen(*s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (!new_s)
		return (0);
	while (*s1 && (*s1)[i])
	{
		new_s[i] = (*s1)[i];
		i++;
	}
	while (s2 && *s2)
	{
		new_s[i++] = *s2;
		s2++;
	}
	if (*s1)
		free(*s1);
	new_s[i] = '\0';
	return (new_s);
}
