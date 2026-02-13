/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:30:59 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/02 11:31:01 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*new_str;

	i = start;
	j = 0;
	total_len = ft_strlen(s) - start;
	if (start >= (size_t)ft_strlen(s))
		total_len = 0;
	else
	{
		if (total_len > len)
			total_len = len;
	}
	new_str = (char *)malloc((total_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (j < total_len && s[i])
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
