/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_character_conversion.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 00:50:31 by scristia      #+#    #+#                 */
/*   Updated: 2022/05/11 14:52:27 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_str(char type, va_list *ap, size_t *bytes, t_spec *base)
{
	char	*s_type;
	long	to_write;
	int		str_len;

	(void)type;
	s_type = va_arg(*ap, char *);
	if (s_type == NULL)
		s_type = "(null)";
	str_len = ft_strlen(s_type);
	if (base->precision < str_len && base->precision >= 0)
		to_write = base->precision;
	else
		to_write = str_len;
	if (base->flags == 0)
		ft_put_pad(base->width - to_write, " ", bytes);
	*bytes += write(1, s_type, to_write);
	if (base->flags == '-')
		ft_put_pad(base->width - to_write, " ", bytes);
}

void	ft_write_char(char type, va_list *ap, size_t *bytes, t_spec *base)
{
	char	c_type;

	if (type == '%')
		c_type = '%';
	else
		c_type = va_arg(*ap, int);
	if (base->flags == '-')
	{
		*bytes += write(1, &c_type, 1);
		ft_put_pad(base->width - 1, " ", bytes);
		return ;
	}
	else if (base->flags == '0' && c_type == '%')
	{
		ft_put_pad(base->width - 1, "0", bytes);
		bytes += write(1, &c_type, 1);
		return ;
	}
	else
		ft_put_pad(base->width - 1, " ", bytes);
	*bytes += write(1, &c_type, 1);
}
