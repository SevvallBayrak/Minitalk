
#include "../minitalk/minitalk.h"

void	ft_btoa(int sig)
{
	static int	bit = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);

	signal(SIGUSR1, ft_btoa);
	signal(SIGUSR2, ft_btoa);

	while (1)
	{
		pause();
	}

	return (0);
}


