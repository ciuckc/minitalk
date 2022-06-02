/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/21 19:18:47 by scristia      #+#    #+#                 */
/*   Updated: 2022/06/02 15:19:15 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static size_t	input_is_invalid(int argc, char **argv)
{
	if (argc != 3)
		return (ft_printf ("Process ID or string missing!\n"));
	if (!ft_isdigit(**(argv + 1)))
		return (ft_printf ("PID must be a valid postive integer!\n"));
	return (0);
}

static void	ack_sig(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "Server done printing!", 21);
		exit(0);
	}
}

static void	send_char(u_int8_t c, u_int32_t srv_pid)
{
	u_int8_t			bits_to_send;
	u_int8_t			bit;
	u_int8_t			sig[2];

	bits_to_send = 8;
	bit = 0;
	sig[0] = SIGUSR2;
	sig[1] = SIGUSR1;
	while (1)
	{
		bit = c & 1;
		c >>= 1;
		bits_to_send--;
		kill(srv_pid, sig[bit]);
		pause();
		if (bits_to_send == 0)
			return ;
	}
}

int	main(int argc, char **argv)
{
	u_int32_t			srv_pid;
	struct sigaction	srv_response;

	if (input_is_invalid(argc, argv))
		return (0);
	srv_pid = ft_atoi(*(argv + 1));
	srv_response.sa_handler = ack_sig;
	sigaction(SIGUSR1, &srv_response, NULL);
	sigaction(SIGUSR2, &srv_response, NULL);
	while (**(argv + 2))
	{
		send_char(**(argv + 2), srv_pid);
		(*(argv + 2))++;
	}
	send_char('\0', srv_pid);
}
