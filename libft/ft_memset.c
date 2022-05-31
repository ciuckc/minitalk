/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:06:51 by scristia      #+#    #+#                 */
/*   Updated: 2021/12/17 17:06:52 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void	*str, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)str + i) = (unsigned char)c;
		i++;
	}
	return ((void *)str);
}
