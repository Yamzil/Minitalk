/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:56:00 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/17 19:56:07 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_sign(char c, pid_t pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & (0x80 >> i))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(500);
	}
}

void	ft_send_string(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_sign(str[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
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
		printf("Try Again with valid argument's numbers \n");
		exit(1);
	}
}
