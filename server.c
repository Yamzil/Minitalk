/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:14:41 by yamzil            #+#    #+#             */
/*   Updated: 2021/12/31 15:30:20 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signum)
{
   static char	c = 0xFF;
   static int	bits = 0;

   if (signum == SIGUSR1)
   {
   	c ^= 0x80 >> bits;
   }
   else if (signum == SIGUSR2)
   {
   	c |= 0x80 >> bits;
   }
   bits++;
   if (bits == 8)
   {
   	bits = 0;
   	c = 0xFF;
   }
}

int	main(void)
{
   pid_t		pid;

   pid = getpid();
   printf("PID: %d\n", pid);
   signal(SIGUSR1, ft_handler);
   signal(SIGUSR2, ft_handler);
   while (1)
   	pause();
}





































