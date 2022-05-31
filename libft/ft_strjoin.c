/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:07:42 by scristia      #+#    #+#                 */
/*   Updated: 2021/12/17 17:07:43 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*full_s;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	full_s = (char *)malloc(len + 1);
	if (full_s == NULL)
		return (full_s);
	while (*s1)
	{
		*full_s = *s1;
		full_s++;
		s1++;
	}
	while (*s2)
	{
		*full_s = *s2;
		full_s++;
		s2++;
	}
	*full_s = '\0';
	return (full_s - len);
}
