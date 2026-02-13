/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:24:30 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/21 12:25:30 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_str;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	if (s1)
	{
		while (*s1)
			new_str[i++] = *s1++;
	}
	if (s2)
	{
		while (*s2)
			new_str[i++] = *s2++;
	}
	new_str[i] = '\0';
	return (new_str);
}

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
