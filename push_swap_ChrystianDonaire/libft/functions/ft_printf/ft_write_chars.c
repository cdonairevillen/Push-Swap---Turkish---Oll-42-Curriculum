/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:16:59 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/17 16:17:05 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_writechar(char c)
{
	char	*raw;

	raw = malloc(2);
	if (!raw)
		return (ft_strdup("(null)"));
	raw[0] = c;
	raw[1] = '\0';
	return (raw);
}

char	*ft_strdup_fix(const char *s)
{
	size_t	len;
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s)
		return (ft_strdup("(null)"));
	len = ft_strlen(s);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
