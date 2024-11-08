/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:39:35 by gbodur            #+#    #+#             */
/*   Updated: 2024/11/08 14:09:51 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long num, int is_uppercase)
{
	int		count;
	char	*base;

	count = 0;
	if (is_uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 16)
		count += ft_print_hex(num / 16, is_uppercase);
	count += ft_putchar(base[num % 16]);
	return (count);
}

int	ft_uns(unsigned int u)
{
	char	buffer[10];
	int		i;
	int		count;

	if (u == 0)
		return (ft_putchar('0'));
	i = 0;
	while (u > 0)
	{
		buffer[i++] = (u % 10) + '0';
		u /= 10;
	}
	count = i;
	while (--i >= 0)
		ft_putchar(buffer[i]);
	return (count);
}
