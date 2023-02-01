/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:24:36 by mbachar           #+#    #+#             */
/*   Updated: 2022/11/18 22:26:33 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long n)
{
	char		*x_lower;

	x_lower = "0123456789abcdef";
	if (n < 16)
		ft_putchar(x_lower[n]);
	if (n >= 16)
	{
		ft_putptr(n / 16);
		ft_putchar(x_lower[n % 16]);
	}
	return (ft_hexlen(n));
}
