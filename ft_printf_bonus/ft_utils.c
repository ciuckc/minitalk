/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 13:28:09 by scristia      #+#    #+#                 */
/*   Updated: 2022/05/17 14:39:04 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int n)
{
	long	i;

	i = (long) n;
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
	}
	if (i <= 9)
	{
		ft_putchar(i % 10 + '0');
	}
	else if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}

size_t	ft_digit_len(unsigned long long number, size_t base)
{
	size_t	len;

	len = 0;
	if (number <= 0)
	{
		number *= -1;
		len++;
	}
	while (number != 0)
	{
		number /= base;
		len++;
	}
	return (len);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
