/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:21:40 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/02 18:21:45 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	turn_even_to_q(unsigned int i, char c)
{
	if (i % 2 == 0)
		c = 'Q';
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*new_str;

	len = ft_strlen(s);
	i = 0;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	if (!s || !f)
		return (NULL);
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
