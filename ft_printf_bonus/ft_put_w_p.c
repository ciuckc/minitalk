/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_w_p.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 16:23:58 by scristia      #+#    #+#                 */
/*   Updated: 2022/05/16 16:36:41 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pad(long n, char *pad_c, size_t *bytes)
{
	while (n > 0)
	{
		*bytes += write(1, pad_c, 1);
		n--;
	}
}

void	ft_flag_pad(long i, t_spec *base, size_t *bytes, size_t is_neg)
{
	if (base->flags == '-')
	{
		if (is_neg)
			*bytes += write(1, "-", 1);
	}
	else if (base->flags == '0')
	{
		if (is_neg)
			*bytes += write(1, "-", 1);
		ft_put_pad(base->width - (i + is_neg), "0", bytes);
	}
	else
		ft_put_pad(base->width - (i + is_neg), " ", bytes);
	if (is_neg && base->flags == 0)
		*bytes += write(1, "-", 1);
}

void	check_prec_width(long *i, unsigned long long n, t_spec *base, int len)
{	
	if (base->precision >= 0 && base->flags == '0')
		base->flags = 0;
	if (base->precision >= 0 && n == 0)
		*i = 0;
	else if (base->precision > len)
		*i = base->precision;
	else
		*i = len;
	if (base->width > base->precision && n == 0)
		return ;
	else if (base->width <= len && base->width >= 0)
		base->width = 0;
}
