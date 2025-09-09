#include "pipex.h"

static int	check_in_quote(char s, int *in_quote, char *qchar)
{
	if ((s == '\'' || s == '"'))
	{
		if (!*in_quote)
		{
			*in_quote = 1;
			*qchar = s;
		}
		else if (*qchar == s)
		{
			*in_quote = 0;
			*qchar = 0;
		}
		return (1);
	}
	return (0);
}

int	size_next_word(char *s, int i)
{
	int 	len;
	int		in_quote;
	char	qchar;

	len = 0;
	in_quote = 0;
	qchar = 0;
	while (s[i])
	{
		if (!in_quote && is_space((unsigned char)s[j]))
			break;
		if (check_in_quote(s[i], &in_quote, &qchar))
		{
			i++;
			continue;
		}
		if (s[i] == '\\' && (in_quote && qchar == '\''))
			len++;
		i++;
		len++;
	}
	return (len);
}

char **get_command(char *s)
{
	int	i;

	while (s[i])
	{
		char *arg = (char *)malloc(size_next_word(s, i) + 1);
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
