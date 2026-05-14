/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meitajima <mtajima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:32:04 by mtajima         #+#    #+#             */
/*   Updated: 2026/05/11 15:32:17 by mtajima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	ft_process(const char *format, int *i, va_list args)
{
	int	ret;

	if (format[*i] == '%' && format[*i + 1])
	{
		ret = ft_convert(format[*i + 1], args);
		if (ret == -1)
			return (-1);
		*i += 2;
		return (ret);
	}
	if (ft_putchar(format[*i]) == -1)
		return (-1);
	(*i)++;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		ret = ft_process(format, &i, args);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		count += ret;
	}
	va_end(args);
	return (count);
}
