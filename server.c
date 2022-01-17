/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:14:41 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/17 15:47:52 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char byte[9];

int ft_power(int nb, int power)
{
    int    d;

    d = nb;
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    if (power == 1)
        return (nb);
    power = power - 2;
    while (power >= 0)
    {
        nb = nb * d;
        power--;
    }
    return (nb);
}

void	ft_binary(char	*str)
{
	int sum;
	int exp;
	int i;
	
	exp = 0;
	sum = 0;
	i  = 0;
	while (str--)
	{
		if (*str == '1')
			sum = sum + ft_power(2, exp);
		exp += 1;
	}
	write (1, &sum, 1);
	i = 0;
}

// void	ft_get_bits(int signum)
// {
// 	static int	i;

// 	i = 0;
// 	while (i < 9)
// 	{
// 		printf("[%d]", i);
// 		if (signum == SIGUSR1)
// 		{
// 			byte[i] = '1';
// 		}
// 		else
// 		{
// 			byte[i] = '0';
// 		}
// 		i++;
// 	}
// 	// printf("[%d]", i);
// 	if (i == 9)
// 	{
// 		ft_putendl_fd(byte, 1);
// 		write(1, &byte, 1);
// 	}
// }

void ft_get_bit(int signum)
{
	int i = 0;
	if (signum == SIGUSR1)
	{
		byte[i] = '1';
		i++;
	}
	write(1, &byte, 1);
}

void ft_get_bit2(int signum)
{
	int i = 0;
	if (signum == SIGUSR2)
	{
		byte[i] = '0';
		i++;
	}
	write(1, &byte, 1);
}

int	main(void)
{
	printf("SERVER'S PID: %d\n", getpid());
	signal(SIGUSR1, ft_get_bit);
	signal(SIGUSR2, ft_get_bit2);
	while (1)
		pause();	
}