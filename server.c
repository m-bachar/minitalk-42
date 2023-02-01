/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:22:04 by mbachar           #+#    #+#             */
/*   Updated: 2023/02/01 12:13:23 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_received(int sig)
{
	ft_printf("%d", 31 - sig);
}

void	ft_bit_to_char()
{
	
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("*** PID = %d *** \n", pid);
	signal(SIGUSR1, sigusr_received);
	signal(SIGUSR2, sigusr_received);
	while (1)
		pause();
}
