/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:38:06 by gbodur            #+#    #+#             */
/*   Updated: 2024/11/08 13:32:30 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_type_check(char type, va_list arg)
{
	int				count;
	unsigned long	ptr;

	count = 0;
	if (type == 'x')
		count += ft_hex(va_arg(arg, unsigned int), 0);
	else if (type == 'X')
		count += ft_hex(va_arg(arg, unsigned int), 1);
	else if (type == 'p')
	{
		ptr = va_arg(arg, unsigned long);
		if (ptr == (unsigned long) NULL)
			ptr += ft_putstr("(nil)");
		else
		{
			count += ft_putstr("0x");
			count += ft_ptr(ptr);
		}
	}
	return (count);
}

static int	ft_type_check2(char type, va_list arg)
{
	int	count;

	count = 0;
	if (type == '%')
		count += ft_putchar('%');
	else if (type == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (type == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (type == 'd')
		count += ft_putnbr(va_arg(arg, int));
	else if (type == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (type == 'u')
		count += ft_uns(va_arg(arg, unsigned int));
	else if (type == 'x' || type == 'X' || type == 'p')
		count += ft_type_check(type, arg);
	else
		return (ft_putchar(type));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			count += ft_type_check2(str[i], arg);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
