/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:14:41 by yamzil            #+#    #+#             */
/*   Updated: 2021/12/28 20:07:35 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void   ft_recieve_msg(int str)
{
    int i;

    i = 0;
    while (j < 8)
    {
        
    }
}

void ft_handler(int signum)
{
    if (signum == SIGUSR1)
    {
        signal(SIGUSR1, ft_handler);
        printf("Event Has Been Recieved Successfully\n");
    }
}
void ft_handlerr(int signum)
{
    if (signum == SIGUSR2)
    {
        signal(SIGUSR2,ft_handlerr);
        printf("Echec !\n");
    }
        
}
int main(void)
{
    printf("Server's PID : %d\n", getpid());
     signal(SIGUSR1, ft_handler);
     signal(SIGUSR2,ft_handlerr);
    // if (signal(SIGUSR1,ft_handler))
    //     printf("SECCESSFULLY");
    // else if (signal(SIGUSR2,ft_handlerr))
    //     printf("ECHEC");
    while(1)
        pause();
}