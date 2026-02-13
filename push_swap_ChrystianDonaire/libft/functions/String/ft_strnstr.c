/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:37:20 by cdonaire          #+#    #+#             */
/*   Updated: 2025/09/30 19:44:14 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == to_find[j])
		{
			while ((str[i + j] == to_find[j])
				&& (to_find[j] != '\0') && i + j < len)
				j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
			else
				j = 0;
		}
		i++;
	}
	return (0);
}
