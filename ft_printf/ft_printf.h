/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayrak <sbayrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:07:14 by sbayrak           #+#    #+#             */
/*   Updated: 2024/11/14 12:10:45 by sbayrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr(int a);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_hex(unsigned int a, char c);
int		ft_unsigned(unsigned int a);
int		ft_point(unsigned long a, int sign);

#endif
