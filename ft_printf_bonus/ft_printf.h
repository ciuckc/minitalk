/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 21:23:10 by scristia      #+#    #+#                 */
/*   Updated: 2022/05/17 16:28:04 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_conversion_specification
{
	long	width;
	long	precision;
	char	flags;
	int		is_p;
}	t_spec;

int		ft_printf(const char *format_string, ...);

void	ft_parse_specifiers(char **fmt, t_spec *base_specifier);

void	ft_write_char(char type, va_list *ap, size_t *bytes, t_spec *base);

void	ft_write_str(char type, va_list *ap, size_t *bytes, t_spec *base);

void	ft_write_int(char type, va_list *ap, size_t *bytes, t_spec *base);

void	ft_write_uint(char type, va_list *ap, size_t *bytes, t_spec *base);

void	ft_write_hex(char type, va_list *ap, size_t *bytes, t_spec *base);

void	ft_write_ptr(char type, va_list *ap, size_t *bytes, t_spec *base);

void	ft_put_pad(long n, char *pad_c, size_t *bytes);

void	check_prec_width(long *i, unsigned long long n, t_spec *base, int len);

void	ft_flag_pad(long write, t_spec *base, size_t *bytes, size_t is_neg);

size_t	ft_strlen(char *str);

void	ft_putnbr(unsigned int n);

void	ft_putchar(char c);

size_t	ft_digit_len(unsigned long long number, size_t base);

#endif
