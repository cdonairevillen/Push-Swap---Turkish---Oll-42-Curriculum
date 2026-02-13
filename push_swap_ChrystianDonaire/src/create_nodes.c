/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:02:45 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/06 18:02:46 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_lstlast_fix(t_node *lst)
{
	t_node	*point;

	point = lst;
	if (!lst)
		return (NULL);
	while (point->next)
		point = point->next;
	return (point);
}

void	ft_lstadd_back_fix(t_node **lst, t_node *new)
{
	t_node	*list;

	list = ft_lstlast_fix(*lst);
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	list = *lst;
	while (list->next)
		list = list->next;
	list->next = new;
	new->prev = list;
}

int	compare_nodes(t_node *list, int num)
{
	while (list)
	{
		if (list->content == num)
			return (0);
		list = list->next;
	}
	return (1);
}

t_node	*ft_lstnew_fix(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = num;
	new->id = -1;
	new->cost_a = 0;
	new->cost_b = 0;
	new->lis = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
