/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:55:43 by aasselma          #+#    #+#             */
/*   Updated: 2023/03/02 18:28:35 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(char *s)
{
	int		r;
	int		sign;
	int		i;

	r = 0;
	sign = 0;
	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10;
		sign = s[i] - '0';
		r = r + sign;
		i++;
	}
	return (r);
}

void	ft_bzero(void *s, int n)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (n > 0)
	{
		str[i] = 0;
		n--;
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = n;
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
	{
		num = num + '0';
		write(1, &num, 1);
	}
}
