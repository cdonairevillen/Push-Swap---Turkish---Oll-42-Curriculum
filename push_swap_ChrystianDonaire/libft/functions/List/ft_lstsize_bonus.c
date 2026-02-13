/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:56:31 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/06 15:22:27 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*point;
	int		size;

	point = lst;
	size = 0;
	if (!lst)
		return (0);
	while (point)
	{
		point = point->next;
		size++;
	}
	return (size);
}
