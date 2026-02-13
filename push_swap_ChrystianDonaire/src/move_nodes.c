/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:08:13 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/16 16:08:15 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_b(t_pile *b, t_node *best)
{
	while (best->cost_b != 0)
	{
		if (best->cost_b > 0)
		{
			rl(NULL, b, 2);
			best->cost_b--;
		}
		else
		{
			rrl(NULL, b, 2);
			best->cost_b++;
		}
	}
	return (1);
}

static int	rotate_a(t_pile *a, t_node *best)
{
	while (best->cost_a != 0)
	{
		if (best->cost_a > 0)
		{
			rl(a, NULL, 1);
			best->cost_a--;
		}
		else
		{
			rrl(a, NULL, 1);
			best->cost_a++;
		}
	}
	return (1);
}

static int	reverse_rotate_both(t_pile *a, t_pile *b, t_node *best)
{
	while (best->cost_a < 0 && best->cost_b < 0)
	{
		rrl(a, b, 3);
		best->cost_a++;
		best->cost_b++;
	}
	return (1);
}

static int	rotate_both(t_pile *a, t_pile *b, t_node *best)
{
	while (best->cost_a > 0 && best->cost_b > 0)
	{
		rl(a, b, 3);
		best->cost_a--;
		best->cost_b--;
	}
	return (1);
}

int	move_node(t_pile *a, t_pile *b, t_node *best)
{
	if (!best)
		return (0);
	if (best->cost_a > 0 && best->cost_b > 0)
		rotate_both(a, b, best);
	else if (best->cost_a < 0 && best->cost_b < 0)
		reverse_rotate_both(a, b, best);
	rotate_a(a, best);
	rotate_b(b, best);
	pl(b, a, 2);
	return (1);
}
