/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:32:29 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/26 18:33:14 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_print(char *s, int fd)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar_print(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}
