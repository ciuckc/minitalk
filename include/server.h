/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/21 16:52:43 by scristia      #+#    #+#                 */
/*   Updated: 2022/06/03 02:08:39 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>

# define TRUE 1
# define BUFFER_SIZE 1024

typedef struct s_srv_data
{
	pid_t	clt_pid;
	char	buffer[BUFFER_SIZE];
}	t_srv_data;

typedef struct s_clt_data
{
	pid_t	srv_pid;
	char	**str;
}	t_clt_data;

#endif
