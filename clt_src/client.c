/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/21 19:18:47 by scristia      #+#    #+#                 */
/*   Updated: 2022/06/03 02:03:30 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_clt_data	clt_data;

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
	static u_int8_t	bit;
	static u_int8_t	bit_pos;

	if (signum == SIGUSR1)
	{
		write(1, "Server done printing!", 21);
		exit(0);
	}
	bit = (**(clt_data.str + 2) >> bit_pos) & 1;
	bit_pos++;
	if (bit_pos == 8)
	{
		bit_pos = 0;
		(*(clt_data.str + 2))++;
	}
	kill(clt_data.srv_pid, SIGUSR1 * (bit & 1) + SIGUSR2 * (bit ^ 1));
}

int	main(int argc, char **argv)
{
	struct sigaction	srv_response;

	if (input_is_invalid(argc, argv))
		return (0);
	clt_data.srv_pid = ft_atoi(*(argv + 1));
	clt_data.str = argv;
	srv_response.sa_flags = SA_SIGINFO;
	sigemptyset(&srv_response.sa_mask);
	sigaddset(&srv_response.sa_mask, SIGUSR1);
	sigaddset(&srv_response.sa_mask, SIGUSR1);
	srv_response.sa_handler = ack_sig;
	sigaction(SIGUSR1, &srv_response, NULL);
	sigaction(SIGUSR2, &srv_response, NULL);
	kill (clt_data.srv_pid, SIGUSR2);
	while (1)
		pause();
}
