/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:27:06 by cdonaire          #+#    #+#             */
/*   Updated: 2025/08/28 17:36:54 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	slen;
	unsigned int	dlen;

	slen = 0;
	dlen = 0;
	i = 0;
	j = 0;
	while (dlen < size && dest[dlen] != '\0')
		dlen++;
	while (src[slen] != '\0')
		slen++;
	if (dlen >= size)
		return (size + slen);
	i = dlen;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src [j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dlen + slen);
}
