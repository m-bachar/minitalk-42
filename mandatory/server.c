/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:22:04 by mbachar           #+#    #+#             */
/*   Updated: 2023/02/04 18:07:38 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t	x_power_y(int x, int y)
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

static void	bit_to_char(int	*bits)
{
	int			ascii;
	int			i;
	int			j;

	i = 7;
	j = 0;
	ascii = 0;
	while (i >= 0)
	{
		ascii += x_power_y(2, i) * bits[j];
		i--;
		j++;
	}
	ft_printf("%c", ascii);
}

static void	sigusr_received(int signum, siginfo_t *data, void *nada)
{
	static int	bits[8];
	static int	i;
	static int	pid;

	nada = NULL;
	if (data->si_pid != pid)
	{
		pid = data->si_pid;
		i = 0;
	}
	if (31 - signum == 0)
		bits[i++] = 0;
	else if (31 - signum == 1)
		bits[i++] = 1;
	if (i == 8)
	{
		bit_to_char(bits);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	moe;
	int					pid;

	moe.sa_sigaction = sigusr_received;
	moe.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("*** PID = %d ***", pid);
	ft_printf("\n");
	sigaction(SIGUSR1, &moe, NULL);
	sigaction(SIGUSR2, &moe, NULL);
	while (1)
		pause();
}
