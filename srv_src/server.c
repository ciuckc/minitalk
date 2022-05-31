/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/21 15:59:43 by scristia      #+#    #+#                 */
/*   Updated: 2022/05/31 20:04:23 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_sig_data	g_sig_data;

static	void	build_char(int signum, siginfo_t *info, void *context)
{
	static u_int8_t	bit_position;

	(void)context;
	g_sig_data.clt_pid = info->si_pid;
	g_sig_data.char_built |= (signum == SIGUSR1) << bit_position;
	bit_position++;
	if (bit_position == 7)
	{
		write(1, &g_sig_data.char_built, 1);
		bit_position = 0;
		if (g_sig_data.char_built == 0)
		{
			kill(g_sig_data.clt_pid, SIGUSR1);
			return ;
		}
		g_sig_data.char_built = 0;
	}
	kill (g_sig_data.clt_pid, SIGUSR2);
}

int	main(void)
{
	pid_t				srv_pid;
	struct sigaction	sig_act;
	size_t				i;

	i = 0;
	srv_pid = getpid();
	ft_printf("My process ID is:\t%d\n", srv_pid);
	sig_act.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_act.sa_mask);
	sig_act.sa_sigaction = build_char;
	sigaction (SIGUSR1, &sig_act, NULL);
	sigaction (SIGUSR2, &sig_act, NULL);
	while (1)
		pause();
}
