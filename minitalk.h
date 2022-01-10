/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:22:24 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/10 19:53:23 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    ft_send_sign(char c, pid_t pid);
void	ft_send_sig(pid_t pid, int sigusr);
void	ft_send_string(char *str, pid_t pid);
void	ft_get_bit(int bit);
#endif