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
		i += (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (i != 0)
			ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	
	while (1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause();
	}
	
	return (0);
}
