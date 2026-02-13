/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:46:32 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/15 15:46:34 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_rotate(t_pile *a)
{
	t_node	*temp;
	int		pos;
	int		size;
	int		steps;

	temp = a->top;
	pos = 0;
	size = a->size;
	while (temp && temp->id != 0)
	{
		temp = temp->next;
		pos++;
	}
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rl(a, NULL, 1);
	}
	else
	{
		steps = size - pos;
		while (steps-- > 0)
			rrl(a, NULL, 1);
	}
}

static void	push_from_lis(t_pile *a, t_pile *b)
{
	int	total;
	int	i;
	int	count;

	i = 0;
	total = a->size;
	count = 0;
	while (i < total)
	{
		if (a->top->lis == 0)
			pl(a, b, 1);
		else
			rl(a, b, 1);
		i++;
	}
}

static t_node	*find_cheapest_node(t_pile *pile)
{
	t_node	*temp;
	t_node	*cheap;
	int		min;

	if (!pile || !pile->top)
		return (NULL);
	temp = pile->top;
	cheap = temp;
	min = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
	while (temp)
	{
		if ((ft_abs(temp->cost_a) + ft_abs(temp->cost_b)) < min)
		{
			min = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
			cheap = temp;
		}
		temp = temp->next;
	}
	return (cheap);
}

int	is_sorted(t_pile *pile)
{
	t_node	*tmp;

	tmp = pile->top;
	while (tmp && tmp->next)
	{
		if (tmp->id + 1 != tmp->next->id)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_numbers(t_pile *a, t_pile *b)
{
	int		moves;
	t_node	*cheap;

	moves = 0;
	cheap = NULL;
	if (a->size <= 5)
		sort_little(a, b);
	else if (!is_sorted(a))
	{
		find_lis(a);
		push_from_lis(a, b);
		while (b->size != 0)
		{
			calculate_costs(a, b);
			cheap = find_cheapest_node(b);
			move_node(a, b, cheap);
		}
		if (!is_sorted(a))
			final_rotate(a);
	}
}
