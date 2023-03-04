/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:55:08 by aasselma          #+#    #+#             */
/*   Updated: 2023/03/02 20:08:28 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_print_str(int *str, int pid)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (i != 8)
	{
		res = res * 2 + str[i];
		i++;
	}
	if (res == '\0')
		kill(pid, SIGUSR1);
	else
		write(1, &res, 1);
}

void	siguser_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static int	str[8];
	static int	pid;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		i = 0;
		ft_bzero(str, 8);
		pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		str[i] = 0;
	else if (signum == SIGUSR2)
		str[i] = 1;
	i++;
	if (i == 8)
	{
		i = 0;
		ft_print_str(str, pid);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sa.sa_sigaction = siguser_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO ;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
