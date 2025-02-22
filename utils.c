/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:54:12 by aelkadir          #+#    #+#             */
/*   Updated: 2025/02/06 23:54:14 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isdigit(int c)
{
	int	result;

	result = (c >= '0' && c <= '9');
	return (result);
}

long	ft_atol(const char *nbr)
{
	int				sign;
	unsigned long	res;

	sign = 1;
	res = 0;
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign = -1;
		nbr++;
	}
	while (ft_isdigit(*nbr))
	{
		if (res > res * 10 + (*nbr - '0'))
			return (2147483649);
		res = res * 10 + (*nbr - '0');
		nbr++;
	}
	return (res * sign);
}

int	is_p_int(long long nbr)
{
	return (nbr <= 2147483647 && nbr > 0);
}

void	ft_putnbr(long n)
{
	char	c;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}
