/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:39:57 by mbachar           #+#    #+#             */
/*   Updated: 2022/11/18 21:23:12 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_hexlen(unsigned long nbr);
int		ft_printf(const char *format, ...);
int		ft_put_unsigned_nbr(unsigned int n);
int		ft_putchar(char c);
int		ft_puthex_lower(unsigned int n);
int		ft_puthex_upper(unsigned int n);
int		ft_putnbr(int n);
int		ft_putptr(unsigned long long n);
int		ft_putstr(char *s);

#endif