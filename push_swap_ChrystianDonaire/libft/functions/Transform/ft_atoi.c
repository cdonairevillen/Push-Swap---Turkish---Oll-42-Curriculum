/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:52:15 by cdonaire          #+#    #+#             */
/*   Updated: 2025/09/30 12:37:49 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	if ((str[i] == '-') || (str[i] == '+'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = 10 * nb +(str[i] - '0');
		i++;
	}
	return (nb * sign);
}
