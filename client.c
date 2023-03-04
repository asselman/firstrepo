/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:22:00 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/28 17:25:42 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(unsigned char c, char *pid_s)
{
	int	ascii_code;
	int	binary[8];
	int	i;
	int	pid;

	ascii_code = c;
	pid = ft_atoi(pid_s);
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
		if (binary[i] == 0)
			kill(pid, SIGUSR1);
		if (binary[i] == 1)
			kill(pid, SIGUSR2);
		i++;
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
		{
			char_to_binary(argv[2][i], argv[1]);
			i++;
		}
	}
	else
	{
		if (argc > 3)
			write(1, "YOU HAVE MORE THAN 3 PARAMETERS ", 32);
		if (argc < 3)
			write(1, "YOU HAVE LESS THAN 3 PARAMETERS ", 32);
	}
	return (0);
}
