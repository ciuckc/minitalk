/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:02:29 by scristia      #+#    #+#                 */
/*   Updated: 2021/12/17 17:02:31 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	sign;
	long	i;

	sign = 1;
	i = 0;
	while (ft_isspace(*str))
		str++;
	while (ft_issign(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (ft_issign(*str))
			return (0);
	}
	while (ft_isdigit(*str))
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (sign * i);
}
