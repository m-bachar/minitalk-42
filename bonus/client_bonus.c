/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:11:00 by mbachar           #+#    #+#             */
/*   Updated: 2023/02/04 18:36:55 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	output;

	i = 0;
	sign = 1;
	output = 0;
	while ((str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{		
		output = output * 10 + (str[i] - 48);
		i++;
	}
	return (output * sign);
}

static void	message_received(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Message sent successfully !\n");
}

static void	ft_ascii_to_bit(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		i--;
	}
}

static void	ft_str_to_bit(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_ascii_to_bit(str[i], pid);
		i++;
	}
	ft_ascii_to_bit('\0', pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		signal(SIGUSR2, message_received);
		pid = ft_atoi(argv[1]);
		if (!pid)
		{
			ft_printf("Error : Wrong process ID !\n");
			exit (0);
		}
		ft_str_to_bit(argv[2], pid);
	}
	else
		ft_printf("Error : Too few or too many arguments !\n");
}
