/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:10:31 by scristia      #+#    #+#                 */
/*   Updated: 2021/12/17 17:10:41 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp_set(char const *s, const int c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_s;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_cmp_set(set, *s1) && *s1)
		s1++;
	len = ft_strlen(s1);
	while (ft_cmp_set(set, *(s1 + len - 1)) && len > 0)
		len--;
	trim_s = (char *)malloc(len + 1);
	if (trim_s == NULL)
		return (trim_s);
	ft_strlcpy(trim_s, s1, len + 1);
	return (trim_s);
}
