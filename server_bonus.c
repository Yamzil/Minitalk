/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:56:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/17 20:28:44 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(int nb, int power)
{
	int	d;

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
	int	sum;
	int	exp;
	int	i;

	exp = 0;
	sum = 0;
	i = 8;
	while (i-- > 0)
	{
		if (str[i] == '1')
			sum = sum + ft_power(2, exp);
		exp += 1;
	}
	ft_putchar(sum);
	i = 0;
}

void	ft_get_bits(int signum)
{
	char		byte [9];
	static int	i = 0;

	if (signum == SIGUSR1)
		byte[i++] = '1';
	else
		byte[i++] = '0';
	if (i == 8)
	{
		ft_binary(byte);
		i = 0;
	}
}

int	main(void)
{
	printf("SERVER'S PID: %d\n", getpid());
	signal(SIGUSR1, ft_get_bits);
	signal(SIGUSR2, ft_get_bits);
	while (1)
		pause();
}
