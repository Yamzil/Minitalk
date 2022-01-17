/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:48:27 by yamzil            #+#    #+#             */
/*   Updated: 2022/01/17 19:41:55 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// CLIENT //

void	ft_send_sign(char c, pid_t pid);
void	ft_send_string(char *str, pid_t pid);

// SERVER //

int		ft_power(int nb, int power);
void	ft_binary(char	*str);
void	ft_get_bit(int signum);

// UTILS //

void	ft_putendl_fd(char *s, int fd);
void	ft_putchar(char c);

#endif
