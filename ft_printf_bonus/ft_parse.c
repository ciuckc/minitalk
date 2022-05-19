/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 19:49:10 by scristia      #+#    #+#                 */
/*   Updated: 2022/05/17 15:47:32 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_atol(char **fmt)
{
	long	number;

	number = 0;
	while (**fmt >= '0' && **fmt <= '9')
	{
		number = number * 10 + (**fmt - '0');
		(*fmt)++;
	}
	return (number);
}

void	ft_parse_specifiers(char **fmt, t_spec *base_specifier)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (base_specifier->flags == '-')
			base_specifier->flags = '-';
		else
			base_specifier->flags = **fmt;
		(*fmt)++;
	}
	if (**fmt >= '0' && **fmt <= '9')
		base_specifier->width = ft_atol(fmt);
	while (**fmt == '.')
	{
		(*fmt)++;
		base_specifier->precision = ft_atol(fmt);
	}
}
