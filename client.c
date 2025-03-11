/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayrak <sbayrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:20:21 by sbayrak           #+#    #+#             */
/*   Updated: 2025/02/27 18:50:24 by sbayrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag = 0;

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	tmp;

	i = 0;
	sign = 1;
	tmp = 0;
	while (str[i] == ' ' || (str[i] <= '\r' && str[i] >= '\t'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = tmp * 10 + str[i] - 48;
		i++;
	}
	return (tmp * sign);
}

void	flg_handler(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 1;
}

void	send_signal(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_flag)
			;
		g_flag = 0;
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Error: wrong format.\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid >= 4194304)
		return (ft_printf("Error: invalid PID.\n"), 1);
	if (kill(pid, 0) == -1)
		return (ft_printf("Error: invalid PID.\n"), 1);
	signal(SIGUSR1, flg_handler);
	message = argv[2];
	while (*message)
		send_signal(pid, *message++);
	send_signal(pid, '\0');
	return (0);
}
