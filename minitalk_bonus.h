/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:56:22 by aasselma          #+#    #+#             */
/*   Updated: 2023/03/02 18:34:58 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    MINITALK_BONUS_H
# define    MINITALK_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int		ft_atoi(char *s);
void	ft_bzero(void *s, int n);
int		ft_strlen(char *str);
void	ft_putnbr_fd(int n, int fd);

#endif