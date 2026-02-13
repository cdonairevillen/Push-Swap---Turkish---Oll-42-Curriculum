/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:18:55 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/02 13:19:00 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_beg(char const *s, char const *set)
{
	size_t	trim_beg;

	trim_beg = 0;
	while (s[trim_beg] && ft_strchr(set, s[trim_beg]) != 0)
		trim_beg++;
	return (trim_beg);
}

static int	ft_trim_end(char const *s, char const *set)
{
	size_t	trim_end;

	trim_end = ft_strlen(s);
	while (trim_end > 0 && ft_strchr(set, s[trim_end - 1]) != 0)
		trim_end--;
	return (trim_end);
}

static char	*ft_empty_set(char const *s)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	i = 0;
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set || *set == '\0')
		return (ft_empty_set(s1));
	len = ft_trim_end(s1, set) - ft_trim_beg(s1, set);
	if (ft_trim_beg(s1, set) >= ft_trim_end(s1, set))
		len = 0;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = s1[ft_trim_beg(s1, set) + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
