/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:14:38 by yamzil            #+#    #+#             */
/*   Updated: 2021/12/31 15:27:01 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char ft_send_sign(char c, pid_t pid)
{
int	i;

i = 7;
while (i <= 0)
{
    if ((c >> i) & 1)
	{
    	printf("1");
    	kill(pid,SIGUSR1);
    }
    else
    {
    	printf("0");
    	kill(pid,SIGUSR2);
    }
	printf("test");
    usleep(500);
	i--;
 }
return(c);
}

int main(int ac, char **av)
{
 pid_t     pid;
 int		i;
 
 i = 0;
 if (ac == 3)
 {
     pid = atoi(av[1]);
     ft_send_sign(av[3][i],pid);
 }
 else
     printf("Number of Arguments is insufficient\n");
     exit(1);
}