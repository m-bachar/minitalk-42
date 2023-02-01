/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:55:28 by mbachar           #+#    #+#             */
/*   Updated: 2022/11/18 02:46:17 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	char	*x_upper;

	x_upper = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(x_upper[n]);
	if (n >= 16)
	{
		ft_puthex_upper(n / 16);
		ft_putchar(x_upper[(n % 16)]);
	}
	return (ft_hexlen(n));
}
