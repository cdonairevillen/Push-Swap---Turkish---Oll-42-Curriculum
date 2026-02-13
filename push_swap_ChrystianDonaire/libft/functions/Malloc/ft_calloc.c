/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:18:17 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/01 19:28:46 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*new_arr;
	size_t	i;

	total = size * nmemb;
	i = 0;
	new_arr = (char *)malloc((total) * sizeof(char));
	if (size == 0 || nmemb == 0)
		return (new_arr);
	if (!new_arr)
		return (NULL);
	while (i < total)
	{
		new_arr[i] = 0;
		i++;
	}
	return (new_arr);
}
