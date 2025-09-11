#include "pipex.h"


static int	create_cmd(char *argv, char **args, int words, char qchar);
static int	have_in_quote(char *argv);
int	size_next_word(char *argv, int i);

/*
	#Check if has quote open and closing like '  '
	if it has 
		pass to count words
	else
		return (ft_split(*arg, ' '));
	
	char **argv = malloc(words * sizeof(char *));

	#Check size of next word in argv[i];
	function have to in count:
	if is in quote, space not end a word;
	if is not int quote, space end a word;

	argv[i] = malloc(size_word * sizeof(char));

	now while (is_not_space && i++)
	while (size_word--)
		argv[i] = argv[i];
*/


char **get_command(char *argv)
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
	if (!args)
		return (NULL);
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
	size_word = -1;
	while (++i < words)
	{
		z = -1;
		while (is_space(argv[++j]));
		size_word = size_next_word(argv, j);
		args[i] = ft_calloc(size_word + 1, sizeof(char));
		if (!args[i])
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

int	size_next_word(char *argv, int i)
{
	int 	len;
	int		in_quote;
	char	qchar;

	len = 0;
	in_quote = 0;
	qchar = 0;
	if (check_in_quote(argv[i], &in_quote, &qchar))
		i++;
	while ((!in_quote && argv[i] != ' ') || (in_quote && argv[i]))
	{
		if (check_in_quote(argv[i], &in_quote, &qchar))
		{
			i++;
			continue;
		}
		if (argv[i] == '\\' && (in_quote && qchar == '\''))
			len++;
		i++;
		len++;
	}
	return (len);
}
