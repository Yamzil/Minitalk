/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:08:36 by yamzil            #+#    #+#             */
/*   Updated: 2021/12/28 20:15:37 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*temp;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	temp = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s1[i])
		temp[n++] = s1[i++];
	i = 0;
	while (s2[i])
		temp[n++] = s2[i++];
	temp[n] = '\0';
	return (temp);
}