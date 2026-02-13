/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:16:59 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/17 16:17:05 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_write_pointer(unsigned long ptr)
{
	int		i;
	char	buff[32];
	char	*base;

	base = "0123456789abcdef";
	i = 2;
	if (ptr == 0 || !ptr)
		return (ft_strdup("(nil)"));
	i = 31;
	buff[i--] = '\0';
	while (ptr > 0)
	{
		buff[i--] = base[ptr % 16];
		ptr = ptr / 16;
	}
	buff[i--] = 'x';
	buff[i] = '0';
	return (ft_strdup(&buff[i]));
}
