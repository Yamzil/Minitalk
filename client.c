/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:14:38 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/16 20:09:23 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_sign(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
    	if (c & (1 << i))
		{
			printf("1");
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			printf("0");
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		i--;
		usleep(500);
	}
}


void	ft_send_string(char *str, pid_t pid)
{
	int		i;
	
	i = 0;
	while(str[i])
	{
		ft_send_sign(str[i], pid);
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
		ft_send_string(av[2], pid);
		exit(0);
 	}
 	else
 	{
    	printf("Arguments are Invalide\n");
    	exit(1);
 	}
}