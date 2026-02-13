/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:30:19 by cdonaire          #+#    #+#             */
/*   Updated: 2025/09/30 18:38:01 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*point;
	unsigned char	ch;

	point = 0;
	ch = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			point = s;
		s++;
	}
	if (ch == 0)
		return ((char *)s);
	return ((char *)point);
}
