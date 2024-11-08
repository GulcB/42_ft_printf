/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:39:35 by gbodur            #+#    #+#             */
/*   Updated: 2024/11/08 13:30:31 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int x, int b)
{
	int	i;

	i = 0;
	if (x >= 16)
		i += ft_hex(x / 16, b);
	if ((x % 16) < 10)
		i += ft_putchar((x % 16) + '0');
	else
	{
		if (b == 0)
			i += ft_putchar((x % 16) + 87);
		else
			i += ft_putchar((x % 16) + 55);
	}
	return (i);
}

int	ft_ptr(unsigned long p)
{
	int	i;

	i = 0;
	if (p >= 16)
		i += ft_ptr(p / 16);
	if ((p % 16) < 10)
		i += ft_putchar((p % 16) + '0');
	else
		i += ft_putchar((p % 16) + 87);
	return (i);
}

int	ft_uns(unsigned int u)
{
	int	i;

	i = 0;
	if (u == 0)
		i += ft_putchar(u + '0');
	else if (u > 0 && u <= 9)
		i += ft_putchar(u + '0');
	else
	{
		i += ft_uns(u / 10);
		i += ft_uns(u % 10);
	}
	return (i);
}
