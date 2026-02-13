/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:45:28 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/16 18:45:29 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_last(t_pile *pile)
{
	int	fid;
	int	sid;
	int	tid;

	fid = pile->top->id;
	sid = pile->top->next->id;
	tid = pile->bot->id;
	if (fid > sid && sid < tid && fid < tid)
		sl(pile, NULL, 1);
	else if (fid > sid && sid > tid)
	{
		sl(pile, NULL, 1);
		rrl(pile, NULL, 1);
	}
	else if (fid > sid && sid < tid && fid > tid)
		rl(pile, NULL, 1);
	else if (fid < sid && sid > tid && fid < tid)
	{
		sl(pile, NULL, 1);
		rl(pile, NULL, 1);
	}
	else if (fid < sid && sid > tid && fid > tid)
		rrl(pile, NULL, 1);
}

void	sort_five(t_pile *a, t_pile *b)
{
	while (a->size > 3)
	{
		if (a->top->id == 0 || a->top->id == 1)
			pl(a, b, 1);
		else
			rl(a, b, 1);
	}
	sort_three_last(a);
	if (b->size == 2 && b->top->id < b->top->next->id)
		sl(a, b, 2);
	while (b->size > 0)
		pl(b, a, 2);
	if (a->top->id > a->top->next->id)
		sl(a, b, 1);
}

static void	sort_two_last(t_pile *pile)
{
	int	fid;
	int	sid;

	fid = pile->top->id;
	sid = pile->top->next->id;
	if (fid > sid)
	{
		sl(pile, NULL, 1);
	}
}

void	sort_little(t_pile *a, t_pile *b)
{
	if (is_sorted(a))
		return ;
	else
	{
		if (a->size == 2)
			sort_two_last(a);
		if (a->size == 3)
			sort_three_last(a);
		if (a->size == 4 || a->size == 5)
			sort_five(a, b);
	}
}
