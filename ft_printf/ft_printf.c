/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayrak <sbayrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:07:08 by sbayrak           #+#    #+#             */
/*   Updated: 2024/11/14 12:49:38 by sbayrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_format(va_list arg, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'p')
		return (ft_point(va_arg(arg, unsigned long), 1));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 'x' || c == 'X')
		return (ft_hex(va_arg(arg, unsigned int), c));
	if (c == 'u')
		return (ft_unsigned(va_arg(arg, unsigned int)));
	return (ft_putchar('%'));
}

static bool	flag_catch(int i, const char *str)
{
	return (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'
			|| str[i + 1] == 'p' || str[i + 1] == 's' || str[i + 1] == 'c'
			|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'
			|| str[i + 1] == 'u'));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		rtn;
	va_list	arg;

	i = -1;
	rtn = 0;
	va_start(arg, str);
	while (str[++i])
	{
		if (flag_catch(i, str))
			rtn += ft_format(arg, str[++i]);
		else
		{
			if (str[i] == '%')
				return (0);
			rtn += ft_putchar(str[i]);
		}
	}
	va_end(arg);
	return (rtn);
}
