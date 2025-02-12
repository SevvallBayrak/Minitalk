/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevvalbayrak <sevvalbayrak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:47:15 by sevvalbayra       #+#    #+#             */
/*   Updated: 2025/02/12 15:48:20 by sevvalbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk/minitalk.h"

void	ft_btoa(int sig)
{
	static int	bit = 0;
	static char	i = 0;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i != 0)
			ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

void	sig_handler(int sig)
{
	ft_btoa(sig);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_handler = sig_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
