/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:09:17 by mbachar           #+#    #+#             */
/*   Updated: 2022/11/18 20:49:26 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lower(unsigned int n)
{
	char	*x_lower;

	x_lower = "0123456789abcdef";
	if (n < 16)
		ft_putchar(x_lower[n]);
	if (n >= 16)
	{
		ft_puthex_lower(n / 16);
		ft_putchar(x_lower[n % 16]);
	}
	return (ft_hexlen(n));
}
