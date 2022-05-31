/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:10:17 by scristia      #+#    #+#                 */
/*   Updated: 2021/12/17 17:10:18 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && n - 1 > 0 && *s1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
