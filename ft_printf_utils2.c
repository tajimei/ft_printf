/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtajima <mtajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:48:11 by mtajima           #+#    #+#             */
/*   Updated: 2026/05/11 19:48:42 by mtajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, int uppercase)
{
	char	*digits;
	int		count;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	count += ft_putchar(digits[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr, 0);
	return (count);
}
