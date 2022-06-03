/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/21 15:59:43 by scristia      #+#    #+#                 */
/*   Updated: 2022/06/03 18:13:28 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server_client.h"

t_srv_data	g_srv_data;

static size_t	write_if_null_or_full(size_t *index)
{
	if (g_srv_data.buffer[*index] == '\0')
	{
		write(1, g_srv_data.buffer, *index);
		ft_memset(g_srv_data.buffer, '\0', *index);
		*index = 0;
		return (1);
	}
	if (*index == BUFFER_SIZE - 1)
	{
		write(1, g_srv_data.buffer, BUFFER_SIZE);
		ft_memset(g_srv_data.buffer, '\0', BUFFER_SIZE);
		*index = 0;
	}
	return (0);
}

static void	build_char(int signum, siginfo_t *info, void *context)
{
	static u_int8_t	bit_position;
	static size_t	index;

	(void)context;
	if (!g_srv_data.clt_pid)
	{
		g_srv_data.clt_pid = info->si_pid;
		kill(g_srv_data.clt_pid, SIGUSR2);
		return ;
	}
	g_srv_data.buffer[index] |= (signum == SIGUSR1) << bit_position;
	bit_position++;
	if (bit_position == 8)
	{
		bit_position = 0;
		if (write_if_null_or_full(&index))
		{
			kill(g_srv_data.clt_pid, SIGUSR1);
			g_srv_data.clt_pid = 0;
			return ;
		}
		index++;
	}
	kill(g_srv_data.clt_pid, SIGUSR2);
}

int	main(void)
{
	pid_t				srv_pid;
	struct sigaction	sig_act;

	srv_pid = getpid();
	ft_printf("My process ID is:\t%d\n", srv_pid);
	sig_act.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_act.sa_mask);
	sigaddset(&sig_act.sa_mask, SIGUSR1);
	sigaddset(&sig_act.sa_mask, SIGUSR1);
	sig_act.sa_sigaction = build_char;
	sigaction (SIGUSR1, &sig_act, NULL);
	sigaction (SIGUSR2, &sig_act, NULL);
	while (1)
		pause();
}
