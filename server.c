/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:54:01 by aelkadir          #+#    #+#             */
/*   Updated: 2025/02/06 23:54:03 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char	octet = 0;
	static int	i = 0;
	static int	prev_pid;

	(void)context;
	if (prev_pid != info->si_pid)
	{
		prev_pid = info->si_pid;
		octet = 0;
		i = 0;
	}
	if (signal == SIGUSR1)
		octet |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &octet, 1);
		i = 0;
		octet = 0;
	}
}

static void	construct(void)
{
	struct sigaction	sig_act;

	sigemptyset(&sig_act.sa_mask);
	sigaddset(&sig_act.sa_mask, SIGUSR1);
	sigaddset(&sig_act.sa_mask, SIGUSR2);
	sig_act.sa_flags = SA_SIGINFO;
	sig_act.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putnbr(pid);
		write(1, "\n", 1);
		construct();
		while (1)
			;
	}
	return (1);
}
