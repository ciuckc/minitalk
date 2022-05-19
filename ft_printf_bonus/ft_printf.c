/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 21:24:01 by scristia      #+#    #+#                 */
/*   Updated: 2022/05/17 15:38:53 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_is_convert(char c)
{
	char	*dictionary;

	dictionary = "%Xcdipsux";
	while (*dictionary)
	{
		if (*dictionary == c)
			return (1);
		dictionary++;
	}
	return (0);
}

static void	ft_conversion(char type, va_list *ap, size_t *bytes, t_spec base)
{
	static void	(*f[128])(char, va_list *, size_t *, t_spec *) = \
	{
	['%'] = ft_write_char, ['c'] = ft_write_char, ['s'] = ft_write_str, \
	['d'] = ft_write_int, ['i'] = ft_write_int, ['u'] = ft_write_uint, \
	['x'] = ft_write_hex, ['X'] = ft_write_hex, ['p'] = ft_write_ptr
	};

	if (!ft_is_convert(type))
		return ;
	(*f[(int)type])(type, ap, bytes, &base);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	size_t		bytes;
	t_spec		base_specifier;

	bytes = 0;
	va_start(ap, fmt);
	base_specifier = (t_spec){0};
	while (*fmt)
	{
		base_specifier = (t_spec){-1, -1, '\0', 0};
		if (*fmt == '%')
		{
			fmt++;
			if (!ft_is_convert(*fmt))
				ft_parse_specifiers((char **)&fmt, &base_specifier);
			ft_conversion(*fmt, &ap, &bytes, base_specifier);
		}
		else
			bytes += write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (bytes);
}
