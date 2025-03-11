/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayrak <sbayrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:07:16 by sbayrak           #+#    #+#             */
/*   Updated: 2024/11/14 12:26:10 by sbayrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int a)
{
	int	ret;

	ret = 0;
	if (a == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (a > 9)
	{
		ret += ft_putnbr(a / 10);
		ret += ft_putnbr(a % 10);
	}
	else if (a < 0)
	{
		ret += ft_putchar('-');
		a = -a;
		ret += ft_putnbr(a);
	}
	else
	{
		ret += ft_putchar(a + '0');
	}
	return (ret);
}

int	ft_putstr(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		ret += ft_putchar(str[i++]);
	return (ret);
}

int	ft_hex(unsigned int a, char c)
{
	int	rtn;

	rtn = 0;
	if (a >= 16)
		rtn += ft_hex(a / 16, c);
	if (c == 'x')
		rtn += write(1, &"0123456789abcdef"[a % 16], 1);
	else if (c == 'X')
		rtn += write(1, &"0123456789ABCDEF"[a % 16], 1);
	return (rtn);
}

int	ft_unsigned(unsigned int a)
{
	int	rtn;

	rtn = 0;
	if (a >= 10)
		rtn += ft_unsigned(a / 10);
	rtn += write(1, &"0123456789"[a % 10], 1);
	return (rtn);
}

int	ft_point(unsigned long a, int sign)
{
	int	rtn;

	rtn = 0;
	if (!a)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (sign == 1)
	{
		rtn += write(1, "0x", 2);
		sign = 0;
	}
	if (a >= 16)
		rtn += ft_point(a / 16, sign);
	rtn += write(1, &"0123456789abcdef"[a % 16], 1);
	return (rtn);
}
