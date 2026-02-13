/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:36:45 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/06 16:36:47 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void	ft_del(void *content)
{
	free (content);
}*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*point;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		point = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = point;
	}
	*lst = NULL;
}
