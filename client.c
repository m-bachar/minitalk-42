/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:21:59 by mbachar           #+#    #+#             */
/*   Updated: 2023/02/03 16:30:22 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_char_to_bit(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

static void	ft_str_to_bit(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_char_to_bit(str[i], pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
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
