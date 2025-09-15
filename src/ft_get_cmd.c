/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:29:34 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/15 16:21:15 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	create_cmd(char *argv, char **args, int words, char qchar);
static int	have_in_quote(char *argv);
static int	size_next_word(char *argv, int i);
static int	alloc_new_word(char *argv, int *j, char **args, int *i);

char	**get_command(char *argv)
{
	char	**args;
	int		words;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!have_in_quote(argv))
		return (ft_split(argv, ' '));
	words = count_words(argv);
	args = ft_calloc(words + 1, sizeof(char *));
	if (!create_cmd(argv, args, words, have_in_quote(argv)))
	{
		ft_free_all(args);
		perror("Malloc failed in create_cmd");
		exit(1);
	}
	return (args);
}

static int	create_cmd(char *argv, char **args, int words, char qchar)
{
	int	i;
	int	j;
	int	z;
	int	size_word;

	i = -1;
	j = -1;
	while (++i < words)
	{
		z = -1;
		size_word = alloc_new_word(argv, &j, args, &i);
		if (size_word == -1)
			return (0);
		if (argv[j] == '\'' || argv[j] == '"')
			j++;
		while (size_word--)
		{
			if (argv[j] == qchar)
				j++;
			args[i][++z] = argv[j++];
		}
	}
	return (1);
}

static int	alloc_new_word(char *argv, int *j, char **args, int *i)
{
	int	size_word;

	while (is_space(argv[++(*j)]))
		continue ;
	size_word = size_next_word(argv, *j);
	args[*i] = ft_calloc(size_word + 1, sizeof(char));
	if (!args[*i])
		return (-1);
	return (size_word);
}

static int	have_in_quote(char *argv)
{
	int		i;
	int		in_quote;
	int		has_quote;
	char	qchar;

	i = -1;
	in_quote = 0;
	has_quote = 0;
	qchar = 0;
	while (argv[++i])
	{
		if (check_in_quote(argv[i], &in_quote, &qchar))
		{
			has_quote = 1;
			if (!qchar)
				qchar = argv[i];
		}
	}
	if (in_quote && has_quote || !has_quote)
		return (0);
	return (qchar);
}

static int	size_next_word(char *argv, int i)
{
	int		len;
	int		in_quote;
	char	qchar;

	len = 0;
	in_quote = 0;
	qchar = 0;
	if (check_in_quote(argv[i], &in_quote, &qchar))
		i++;
	while (argv[i] && ((!in_quote && (argv[i] != ' ')
			) || (in_quote && argv[i])))
	{
		if (qchar == argv[i] && check_in_quote(argv[i], &in_quote, &qchar))
		{
			i++;
			continue ;
		}
		if (argv[i] == '\\' && (in_quote && qchar == '\''))
			len++;
		i++;
		len++;
	}
	return (len);
}
