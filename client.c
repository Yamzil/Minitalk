/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:14:38 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/08 18:52:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_sig(pid_t pid, int sigusr)
{
	if (sigusr == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep (500);
}

void	ft_send_sign(char c, pid_t pid)
{
	int	i;
	int bit;

	i = 7;
	while (i <= 0)
	{
    	if ((bit = (c >> i)) & 1)
			ft_send_sig(pid, bit);
		else 
			ft_send_sig(pid, bit);
		i--;
	}
}

int main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		ft_send_sign(av[2][i], pid);
 	}
 	else
 	{
    	printf("Number of Arguments is insufficient\n");
    	exit(1);
 	}
}