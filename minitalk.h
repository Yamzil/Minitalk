/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:22:24 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/17 15:01:52 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// CLIENT //

void	ft_send_sign(char c, pid_t pid);
void	ft_send_string(char *str, pid_t pid);

// SERVER //

int ft_power(int nb, int power);
void	ft_binary(char	*str);
void	ft_get_bit(int signum);

// UTILS //

void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif