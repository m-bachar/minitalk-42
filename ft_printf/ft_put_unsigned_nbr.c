/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:26:56 by mbachar           #+#    #+#             */
/*   Updated: 2022/11/18 22:50:44 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_nbrlen(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_put_unsigned_nbr(unsigned int n)
{
	int	len;

	len = ft_nbrlen(n);
	if (n <= 9)
	{
		ft_putchar(n + 48);
	}
	if (n > 9)
	{
		ft_put_unsigned_nbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	return (len);
}
