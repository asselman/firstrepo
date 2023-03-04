/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:22:00 by aasselma          #+#    #+#             */
/*   Updated: 2023/03/02 19:05:14 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_signal(int pid, int binary)
{
	if (binary == 0)
	{
		if (kill(pid, SIGUSR1) != 0)
		{
			write(1, "Invalid signal number or invalid PID\n", 37);
			exit(1);
		}
	}
	if (binary == 1)
	{
		if (kill(pid, SIGUSR2) != 0)
		{
			write(1, "Invalid signal number or invalid PID\n", 37);
			exit(1);
		}
	}
}

void	char_to_binary(unsigned char c, int pid)
{
	int	ascii_code;
	int	binary[8];
	int	i;

	ascii_code = c;
	i = 7;
	while (i != -1)
	{
		binary[i] = ascii_code % 2;
		ascii_code = ascii_code / 2;
		i--;
	}
	i = 0;
	while (i <= 7)
	{
		send_signal(pid, binary[i]);
		i++;
		usleep(100);
	}
}

void	msg_rec(int signum)
{
	(void)signum;
	write(1, "\033[32m[MESSAGE RECIVED!]\033[0m\n", 28);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argv[1])
		pid = ft_atoi(argv[1]);
	signal(SIGUSR1, msg_rec);
	if (argc == 3)
	{
		while (i != ft_strlen(argv[2]) + 1)
		{
			char_to_binary(argv[2][i], pid);
			usleep(200);
			i++;
		}
	}
	else
	{
		if (argc > 3)
			write(1, "YOU HAVE MORE THAN 3 PARAMETERS\n", 33);
		if (argc < 3)
			write(1, "YOU HAVE LESS THAN 3 PARAMETERS\n", 33);
	}
	return (0);
}
