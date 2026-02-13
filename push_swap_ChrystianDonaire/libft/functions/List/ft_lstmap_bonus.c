/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:09:31 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/06 17:09:33 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void	*ft_duplicate_upper(void *content)
{
	char	*str;
	char	*copy;
	int		i;

	i = 0;
	str = (char *)content;
	copy = strdup(str);
	if (!copy)
		return (NULL);
	while (copy[i])
	{
		if (copy[i] >= 'a' && copy[i] <= 'z')
			copy[i] = copy[i] - 32;
		i++;
	}
	return (copy);
}

static void	ft_del(void *content)
{
	free (content);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	void	*new_content;

	new_content = NULL;
	new_list = (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		if (new_content == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_obj = ft_lstnew(new_content);
		if (!new_obj)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = (lst)->next;
	}
	return (new_list);
}
