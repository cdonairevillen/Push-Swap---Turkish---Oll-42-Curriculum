/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:58:23 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/06 15:58:25 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_pile(t_pile **pile, t_node *list)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = list;
	(*pile)->top = list;
	while (temp && temp->next)
	{
		temp = temp->next;
		i++;
	}
	if (temp)
		i++;
	(*pile)->bot = temp;
	(*pile)->size = i;
}

void	set_index(t_node *list)
{
	int		id;
	t_node	*a;
	t_node	*b;

	a = list;
	while (a)
	{
		id = 0;
		b = list;
		while (b)
		{
			if (b->content < a->content)
				id++;
			b = b->next;
		}
		a->id = id;
		a = a->next;
	}
}

void	set_numbers(t_node *list)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = malloc(sizeof(t_pile));
	pile_b = malloc(sizeof(t_pile));
	set_pile(&pile_a, list);
	set_pile(&pile_b, NULL);
	sort_numbers(pile_a, pile_b);
	free_for_all (&pile_a->top);
	free (pile_a);
	free (pile_b);
}

int	main(int argc, char *argv[])
{
	t_node	*list;

	list = NULL;
	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &list))
	{
		free_for_all(&list);
		return (0);
	}
	set_index(list);
	set_numbers(list);
	return (0);
}
