/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:10:46 by scristia      #+#    #+#                 */
/*   Updated: 2021/12/17 17:10:47 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char const *s, char *sub_s, size_t len)
{
	while (len > 0 && *s)
	{
		*sub_s = *s;
		sub_s++;
		s++;
		len--;
	}
	*sub_s = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	s += start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub_s = (char *)malloc(len + 1);
	if (sub_s == NULL)
		return (sub_s);
	ft_strcpy(s, sub_s, len);
	return (sub_s);
}
