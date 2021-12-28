/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:14:38 by yamzil            #+#    #+#             */
/*   Updated: 2021/12/28 18:14:23 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char    *ft_conver_send(char *str, pid_t pid)
{
    int i;
    int bit;

    i = 0;

    while(str[i++])
    {
        bit = 0;
        while (bit <= 8)
        {
            if (str[i] >> 1 & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            bit++;
        }
    }
    return(&str[i]);
}
int main(int ac, char **av)
{
   int  pid;

   if (ac == 3)
   {
       pid = atoi(av[1]);
       ft_conver_send(av[2],pid);
   }
}