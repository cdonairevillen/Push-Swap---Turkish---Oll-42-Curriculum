/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:08:29 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/15 20:08:31 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_lis(t_node *best, t_pile *a)
{
	int		id;
	t_node	*temp;

	best->lis = 1;
	id = best->id;
	if (best->next != NULL)
		temp = best->next;
	else
		temp = a->top;
	while (temp != best)
	{
		if (temp->id > id)
		{
			temp->lis = 1;
			id = temp->id;
		}
		else
			temp->lis = 0;
		if (temp->next)
			temp = temp->next;
		else
			temp = a->top;
	}
}

static t_node	*find_best_lis(t_node *node, int *max_len, t_pile *a)
{
	t_node	*temp;
	int		len;
	int		id;

	len = 1;
	id = node->id;
	if (node->next != NULL)
		temp = node->next;
	else
		temp = a->top;
	while (temp != node)
	{
		if (temp->id > id)
		{
			len++;
			id = temp->id;
		}
		if (temp->next != NULL)
			temp = temp->next;
		else
			temp = a->top;
	}
	if (len > *max_len)
		return (*max_len = len, node);
	return (NULL);
}

void	find_lis(t_pile *a)
{
	t_node	*node;
	int		max_len;
	t_node	*best;
	t_node	*temp;

	node = a->top;
	max_len = 0;
	best = NULL;
	while (node)
	{
		node->lis = 0;
		node = node->next;
	}
	node = a->top;
	while (node)
	{
		temp = find_best_lis(node, &max_len, a);
		if (temp)
			best = temp;
		node = node->next;
	}
	if (best != NULL)
		check_lis(best, a);
}

int	only_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == ' ' || s[i] == '\t' || (s[i] >= 9 && s[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}
