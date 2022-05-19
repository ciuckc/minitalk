/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_decimal_conversion.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/08 21:21:20 by scristia      #+#    #+#                 */
/*   Updated: 2022/05/16 13:10:04 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_isnegative(long n)
{
	return (n < 0);
}

static void	put_digits(unsigned int n, int is_neg, size_t *bytes, t_spec *base)
{
	int		len;
	long	to_write;

	to_write = 0;
	len = ft_digit_len(n, 10);
	check_prec_width(&to_write, n, base, len);
	ft_flag_pad(to_write, base, bytes, is_neg);
	if (n == 0 && base->precision == 0)
		len = 0;
	else if (n == 0 && base->precision > 0)
	{
		ft_put_pad(base->precision, "0", bytes);
		len = 0;
	}
	else
		ft_put_pad(base->precision - len, "0", bytes);
	if (to_write != 0)
		ft_putnbr(n);
	if (base->flags == '-')
		ft_put_pad(base->width - (to_write + is_neg), " ", bytes);
	*bytes += len;
}

void	ft_write_uint(char type, va_list *ap, size_t *bytes, t_spec *base)
{
	unsigned int	number;

	(void)type;
	number = va_arg(*ap, unsigned int);
	put_digits(number, 0, bytes, base);
}

void	ft_write_int(char type, va_list *ap, size_t *bytes, t_spec *base)
{
	int		number;
	int		is_negative;

	(void)type;
	number = va_arg(*ap, int);
	is_negative = ft_isnegative(number);
	if (is_negative)
		number *= -1;
	put_digits(number, is_negative, bytes, base);
}
