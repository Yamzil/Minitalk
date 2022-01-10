/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:14:38 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/10 19:45:00 by yamzil           ###   ########.fr       */
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
	int	bit;

	i = 0;
	while (i < 8)
	{
    	if ((bit = (i >> c)) & 0x1)
			ft_send_sig(pid, bit);
		else 
			ft_send_sig(pid, bit);
		i++;
	}
}

void	ft_send_string(char *str, pid_t pid)
{
	int		i;
	char	c;
	
	i = 0;
	c = str[i];
	while(str[i])
	{
		if ((i >> c) & 0x1)
			ft_send_sign(c, pid);
		else 
			ft_send_sign(c, pid);
		i++;
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
		ft_send_string(&av[2][i], pid);
		// ft_send_sign(av[2][i], pid);
		exit(0);
 	}
 	else
 	{
    	printf("Number of Arguments is insufficient\n");
    	exit(1);
 	}
}