/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:33:28 by cdonaire          #+#    #+#             */
/*   Updated: 2025/09/30 18:33:01 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	value;
	unsigned char	*byte_str;
	size_t			i;

	value = (unsigned char)c;
	byte_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		byte_str[i] = value;
		i++;
	}
	return (str);
}
