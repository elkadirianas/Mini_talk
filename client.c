/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:53:55 by aelkadir          #+#    #+#             */
/*   Updated: 2025/02/06 23:53:56 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ex(void)
{
	write(2, "failed to send SIG\n", 19);
	exit(1);
}

static void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = 1 & (c >> i);
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ex();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ex();
		}
		usleep(450);
		i++;
	}
}

static void	send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(2, "require pid and a msg\n", 22);
	else
	{
		if (!is_p_int(ft_atol(argv[1])))
			write(2, "pid should be a positive integer\n", 33);
		else if (argv[2][0] == '\0')
			write(2, "the msg cannot be empty\n", 25);
		else if (kill(ft_atol(argv[1]), 0) == -1)
			write(2, "no server we can send to runing with this pid\n", 47);
		else
			send_msg(ft_atol(argv[1]), argv[2]);
	}
	return (1);
}
