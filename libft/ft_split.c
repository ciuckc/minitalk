/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:07:15 by scristia      #+#    #+#                 */
/*   Updated: 2022/02/15 19:28:35 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clean(char **split)
{
	size_t	i;

	i = 0;
	while (*(split + i) != NULL)
	{
		free(*(split + i));
		i++;
	}
	free(split);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	word_count;
	size_t	is_delim;

	is_delim = 1;
	word_count = 0;
	while (*s != 0)
	{
		if (*s != c && is_delim == 1)
		{
			word_count++;
			is_delim = 0;
		}
		else if (*s == c)
			is_delim = 1;
		s++;
	}
	return (word_count);
}

static int	ft_copy_str(char *s, char c, size_t word_count, char **split)
{
	size_t	current_word;
	size_t	len;

	current_word = 0;
	len = 0;
	while (*s == c)
		s++;
	while (current_word < word_count)
	{
		if (!ft_strchr(s, c))
			len = ft_strlen(s);
		else
			len = ft_strchr(s, c) - s;
		*(split + current_word) = ft_substr(s, 0, len);
		if (*(split + current_word) == NULL)
			return (0);
		s += len;
		while (*s == c)
			s++;
		current_word++;
	}
	*(split + current_word) = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*str;
	size_t	word_count;

	if (s == NULL)
		return ((char **) s);
	str = (char *) s;
	word_count = ft_count_words(str, c);
	split = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (split == NULL)
		return (split);
	if (!ft_copy_str(str, c, word_count, split))
		ft_clean(split);
	return (split);
}
