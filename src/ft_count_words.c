/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:56:07 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/09 21:56:08 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int count_words(char *s)
{
	char qchar;
	int in_quote;
	int count;
	int i;

	qchar = 0;
	in_quote = 0;
	count = 0;
	i = 0;
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
					in_quote = 1;
					qchar = s[i];
				}
				else if (qchar == s[i])
				{
					in_quote = 0;
					qchar = 0;
				}
				i++;
				continue;
			}
			if (s[i] == '\\' && (!in_quote || qchar == '"') && s[i + 1])
			{
				i += 2; /* skip the backslash, take next literally */
				continue;
			}
			i++;
		}
	}
	if (in_quote)
		return ft_split(s, ' ');
}
