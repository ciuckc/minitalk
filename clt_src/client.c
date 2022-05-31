/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/21 19:18:47 by scristia      #+#    #+#                 */
/*   Updated: 2022/05/31 19:53:04 by scristia      ########   odam.nl         */
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
		write(1, "Server done printing!", 21);
}

static void	send_char(u_int8_t c, u_int32_t srv_pid)
{
	struct sigaction	wait_srv_response;
	u_int8_t			bits_to_send;
	u_int8_t			bit;

	wait_srv_response.sa_handler = ack_sig;
	bits_to_send = 7;
	bit = 0;
	while (bits_to_send > 0)
	{
		bit = c & 1;
		c >>= 1;
		bits_to_send--;
		kill(srv_pid, SIGUSR1 * (bit == 1) + SIGUSR2 * (bit == 0));
		sigaction(SIGUSR2, &wait_srv_response, NULL);
		pause();
	}
}

int	main(int argc, char **argv)
{
	u_int32_t			srv_pid;
	struct sigaction	srv_finished;

	if (input_is_invalid(argc, argv))
		return (0);
	srv_pid = ft_atoi(*(argv + 1));
	srv_finished.sa_handler = ack_sig;
	sigaction(SIGUSR1, &srv_finished, NULL);
	sigaction(SIGUSR2, &srv_finished, NULL);
	while (**(argv + 2))
	{
		send_char(**(argv + 2), srv_pid);
		(*(argv + 2))++;
	}
	send_char('\0', srv_pid);
	pause();
}
