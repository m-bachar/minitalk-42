/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:23:46 by mbachar           #+#    #+#             */
/*   Updated: 2022/11/18 22:35:16 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_next(va_list args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = i + ft_putchar(va_arg(args, int));
	if (c == 's')
		i = i + ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		i = i + ft_putnbr(va_arg(args, int));
	if (c == 'u')
		i = i + ft_put_unsigned_nbr(va_arg(args, unsigned int));
	if (c == 'x')
		i = i + ft_puthex_lower(va_arg(args, unsigned int));
	if (c == 'X')
		i = i + ft_puthex_upper(va_arg(args, unsigned int));
	if (c == 'p')
	{
		i = i + write(1, "0x", 2);
		i = i + ft_putptr(va_arg(args, unsigned long long));
	}
	if (c == '%')
		i = i + ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			len = len + ft_check_next(args, str[i + 1]);
			i++;
		}
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
