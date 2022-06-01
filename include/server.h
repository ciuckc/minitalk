/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/21 16:52:43 by scristia      #+#    #+#                 */
/*   Updated: 2022/06/01 18:54:59 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>

# define TRUE 1

typedef struct s_sig_data
{
	u_int8_t	char_built;
	pid_t		clt_pid;
}	t_sig_data;

#endif
