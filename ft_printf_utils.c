/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meitajima <mtajima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:19:10 by mtajima         #+#    #+#             */
/*   Updated: 2026/05/11 15:19:19 by mtajima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	return (write(1, &ch, 1));
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		index++;
	}
	return (index);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		return (ft_putstr("(null)"));
	len = ft_strlen(str);
	if (write(1, str, len) == -1)
		return (-1);
	return (len);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		count += ft_putunsigned(nb / 10);
	count += ft_putchar('0' + (nb % 10));
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	count += ft_putchar('0' + (n % 10));
	return (count);
}
