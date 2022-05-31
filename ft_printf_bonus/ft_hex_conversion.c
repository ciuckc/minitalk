/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_conversion.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 12:47:16 by scristia      #+#    #+#                 */
/*   Updated: 2022/05/20 15:37:12 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_reverse(char *hex, int i)
{
	while (i >= 0)
	{
		write(1, &hex[i], 1);
		i--;
	}
}

static void	put_hex(u_int64_t n, size_t low_or_up)
{
	char	*dictionary;
	char	*hex;
	size_t	i;

	dictionary = "0123456789abcdef0123456789ABCDEF";
	hex = (char [17]){0};
	i = 0;
	if (n == 0)
		write(1, "0", 1);
	while (n)
	{
		hex[i] = dictionary[n % 16 + low_or_up];
		n /= 16;
		i++;
	}
	ft_print_reverse(hex, i - 1);
}

static void	conv_hex(u_int64_t n, size_t uplow, size_t *bytes, t_spec *base)
{
	long	to_write;
	size_t	hex_len;

	to_write = 0;
	hex_len = ft_digit_len(n, 16) + base->is_p;
	check_prec_width(&to_write, n, base, hex_len);
	ft_flag_pad(to_write, base, bytes, 0);
	if (n == 0 && base->precision == 0)
		hex_len = 0;
	else if (n == 0 && base->precision > 0)
	{
		ft_put_pad(base->precision, "0", bytes);
		hex_len = 0;
	}
	else
		ft_put_pad(base->precision - hex_len, "0", bytes);
	if (base->is_p == 2)
		write(1, "0x", 2);
	if (to_write)
		put_hex(n, uplow);
	if (base->flags == '-')
		ft_put_pad(base->width - to_write, " ", bytes);
	*bytes += hex_len;
}

void	ft_write_hex(char type, va_list *ap, size_t *bytes, t_spec *base)
{
	unsigned int	number;
	size_t			low_or_up;

	number = va_arg(*ap, unsigned int);
	low_or_up = 0;
	if (type == 'X')
		low_or_up = 16;
	conv_hex(number, low_or_up, bytes, base);
}

void	ft_write_ptr(char type, va_list *ap, size_t *bytes, t_spec *base)
{
	unsigned long long	n;

	(void)type;
	n = va_arg(*ap, unsigned long long);
	base->is_p = 2;
	conv_hex(n, 0, bytes, base);
}
