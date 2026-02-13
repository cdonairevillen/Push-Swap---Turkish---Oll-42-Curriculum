/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:25:09 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/15 16:25:11 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_usable_best(t_pile *a)
{
	t_node	*temp;
	t_node	*best;
	int		id;

	temp = a->top;
	best = NULL;
	id = INT_MAX;
	while (temp)
	{
		if (temp->id < id)
		{
			id = temp->id;
			best = temp;
		}
		temp = temp->next;
	}
	return (best);
}

static t_node	*find_target_node(t_pile *a, t_node *b)
{
	t_node	*temp;
	t_node	*best;
	int		id;

	temp = a->top;
	best = NULL;
	id = INT_MAX;
	while (temp)
	{
		if (temp->id > b->id && temp->id < id)
		{
			id = temp->id;
			best = temp;
		}
		temp = temp->next;
	}
	if (!best)
		best = find_usable_best(a);
	return (best);
}

static void	cost_a(t_pile *a, t_node *temp, int half_a)
{
	int		pos;
	t_node	*a_temp;
	t_node	*target;

	pos = 0;
	a_temp = a->top;
	target = find_target_node(a, temp);
	while (a_temp && a_temp != target)
	{
		pos++;
		a_temp = a_temp->next;
	}
	if (pos <= half_a)
		temp->cost_a = pos;
	else
		temp->cost_a = pos - a->size;
}

static void	cost_b(t_pile *b, t_node *temp, int half_b)
{
	int		pos;
	t_node	*b_temp;

	pos = 0;
	b_temp = b->top;
	while (b_temp && b_temp != temp)
	{
		pos++;
		b_temp = b_temp->next;
	}
	if (pos <= half_b)
		temp->cost_b = pos;
	else
		temp->cost_b = pos - b->size;
}

void	calculate_costs(t_pile *a, t_pile *b)
{
	t_node	*temp;
	int		half_a;
	int		half_b;

	temp = b->top;
	half_a = a->size / 2;
	half_b = b->size / 2;
	while (temp)
	{
		cost_b(b, temp, half_b);
		cost_a(a, temp, half_a);
		temp = temp->next;
	}
}
