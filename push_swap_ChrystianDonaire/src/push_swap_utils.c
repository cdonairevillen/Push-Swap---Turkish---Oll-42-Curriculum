/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:02:45 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/06 18:02:46 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_loop(t_node *temp, t_node *node, t_pile *a)
{
	if (node->next)
		temp = node->next;
	else
		temp = a->top;
}

void	free_for_all(t_node **lst)
{
	t_node	*point;

	while (*lst)
	{
		point = (*lst)->next;
		free (*lst);
		*lst = point;
	}
	*lst = NULL;
}

long	ft_atol(char *str)
{
	int		i;
	long	nb;
	int		sign;

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

void	free_elems(char **elem)
{
	int	i;

	i = 0;
	while (elem[i])
	{
		free (elem[i]);
		i++;
	}
	free (elem);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
