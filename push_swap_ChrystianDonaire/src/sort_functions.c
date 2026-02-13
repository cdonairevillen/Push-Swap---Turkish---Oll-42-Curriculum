/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:26:58 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/07 14:27:02 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_list(t_pile *pile)
{
	t_node	*frt;
	t_node	*sec;

	if (!pile || pile->size < 2)
		return (0);
	frt = pile->top;
	sec = frt->next;
	frt->next = sec->next;
	if (sec->next)
		sec->next->prev = frt;
	else
		pile->bot = frt;
	sec->prev = NULL;
	sec->next = frt;
	frt->prev = sec;
	pile->top = sec;
	return (1);
}

int	push_list(t_pile *pile_a, t_pile *pile_b)
{
	t_node	*temp;

	if (!pile_a || !pile_a->top)
		return (0);
	temp = pile_a->top;
	pile_a->top = pile_a->top->next;
	if (pile_a->top)
		pile_a->top->prev = NULL;
	else
		pile_a->bot = NULL;
	temp->next = pile_b->top;
	if (pile_b->top)
		pile_b->top->prev = temp;
	else
		pile_b->bot = temp;
	temp->prev = NULL;
	pile_b->top = temp;
	pile_a->size--;
	pile_b->size++;
	return (1);
}

int	rotate_list(t_pile *pile)
{
	t_node	*frt;
	t_node	*last;

	if (!pile || pile->size < 2)
		return (0);
	frt = pile->top;
	last = pile->bot;
	pile->top = frt->next;
	pile->top->prev = NULL;
	last->next = frt;
	frt->prev = last;
	frt->next = NULL;
	pile->bot = frt;
	return (1);
}

int	reverse_rotate_list(t_pile *pile)
{
	t_node	*frt;
	t_node	*last;

	if (!pile || pile->size < 2)
		return (0);
	frt = pile->top;
	last = pile->bot;
	pile->bot = last->prev;
	pile->bot->next = NULL;
	pile->top = last;
	last->prev = NULL;
	last->next = frt;
	frt->prev = last;
	return (1);
}
