/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:22:24 by yamzil            #+#    #+#             */
/*   Updated: 2021/12/28 17:17:58 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

char	ft_send_convert(char *str, pid_t pid);
void    ft_handler(int signum);
void    ft_handlerr(int signum);
#endif