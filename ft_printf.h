/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meitajima <mtajima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:25:51 by mtajima         #+#    #+#             */
/*   Updated: 2026/05/11 15:26:11 by mtajima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned long n, int uppercase);
int		ft_putptr(void *ptr);

#endif