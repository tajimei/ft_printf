/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtajima <mtajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:48:11 by mtajima           #+#    #+#             */
/*   Updated: 2026/05/15 01:41:03 by mtajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, int uppercase)
{
	char	*digits;
	int		count;
	int		ret;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		ret = ft_puthex(n / 16, uppercase);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar(digits[n % 16]);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;
	int	ret;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	ret = ft_putstr("0x");
	if (ret == -1)
		return (-1);
	count += ret;
	ret = ft_puthex((unsigned long)ptr, 0);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
