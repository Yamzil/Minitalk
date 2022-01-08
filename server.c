/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:14:41 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/03 13:58:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void  ft_get_bit(int bit)
{
   static char	ret;
   int 			i;

   i = 0;
   bit = 7;
   while(bit <= i)
   {
	   if (bit == SIGUSR1)
		   ret = ret | (1 << bit);
		bit++;
		i--;
   }		
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	while (1)
	{
		signal (SIGUSR1, ft_get_bit);
		signal (SIGUSR2, ft_get_bit);
	}
}





































