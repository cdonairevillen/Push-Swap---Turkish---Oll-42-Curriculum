/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:45:41 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/02 14:45:44 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static char	*ft_malloc_word(char const *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(i + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	**ft_free_all_split(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**new_arr;

	i = 0;
	j = 0;
	new_arr = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!new_arr)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			new_arr[j] = ft_malloc_word(&s[i], c);
			if (!new_arr[j])
				return ((char **)ft_free_all_split(new_arr));
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	new_arr[j] = (NULL);
	return (new_arr);
}
