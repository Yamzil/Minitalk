/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:14:41 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/10 20:09:05 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_power(int base, int exp)
{
	int b;
	
	b = base;
	while ((exp - 1) != 0)
	{
		base *= b;
		exp--;
	}
	return(base);	
}

void	ft_get_bit(int bit)
{
	char b;

	b = bit;
	while (bit < 8)
	{
		if (b == SIGUSR1)
			b += ft_power(2 , b);
		else
			b += ft_power(2 , b);
	}
	printf("SIGNAL RECIVIED !\n");
	printf("%c\n", b);
}

int	main(void)
{
	printf("SERVER'S PID: %d\n", getpid());
	signal (SIGUSR1, ft_get_bit);
	signal (SIGUSR2, ft_get_bit);
	while (1);
}





































