/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:22:04 by mbachar           #+#    #+#             */
/*   Updated: 2023/02/03 16:46:22 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	x_power_y(int x, int y)
{
	int	z;

	z = 1;
	while (y > 0)
	{
		z *= x;
		y--;
	}
	return (z);
}

void	bit_to_char(int	*bits)
{
	int	ascii;
	int	i;
	int	j;

	i = 7;
	j = 0;
	ascii = 0;
	while (i >= 0)
	{
		ascii += x_power_y(2, i) * bits[j];
		i--;
		j++;
	}
	write(1, &ascii, 1);
}

void	sigusr_received(int signum)
{
	static int	bits[8];
	static int	i;
	int			j;

	j = 0;
	if (31 - signum == 0)
	{
		bits[i] = 0;
		i++;
	}
	else if (31 - signum == 1)
	{
		bits[i] = 1;
		i++;
	}
	if (i == 8)
	{
		bit_to_char(bits);
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("*** PID = %d ***", pid);
	ft_printf("\n");
	signal(SIGUSR1, sigusr_received);
	signal(SIGUSR2, sigusr_received);
	while (1)
		pause();
}
