/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:58:06 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/29 15:58:48 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_set_sign(char *newstr, t_var fmt, int start, char *raw)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(raw))
	{
		newstr[start + i] = raw[i];
		i++;
	}
	if (fmt.sign)
	{
		if (fmt.minus || (fmt.zero && !fmt.point))
			newstr[0] = fmt.sign;
		else
		{
			while (newstr[j] == ' ')
				j++;
			newstr[j - 1] = fmt.sign;
		}
	}
	return (newstr);
}

static char	*ft_set_start(char *newstr, t_var fmt, int total_len, char *raw)
{
	int	start;

	start = 0;
	if (fmt.minus)
		start = 1 * (fmt.sign != 0);
	else
		start = total_len - ft_strlen(raw);
	newstr = ft_set_sign(newstr, fmt, start, raw);
	return (newstr);
}

static char	*ft_format_builder(char *newstr, t_var fmt, int total_len)
{
	int	i;

	i = 0;
	while (i < total_len)
	{
		if (fmt.zero && !fmt.minus && !fmt.point)
			newstr[i] = '0';
		else
			newstr[i] = ' ';
		i++;
	}
	newstr[total_len] = '\0';
	return (newstr);
}

char	*ft_apply_sign(char *raw, t_var fmt)
{
	char	*newstr;
	int		total_len;

	total_len = ft_strlen(raw);
	if (fmt.sign)
		total_len += 1;
	if (fmt.width > total_len)
		total_len = fmt.width;
	newstr = malloc(total_len + 1);
	if (!newstr)
		return (raw);
	newstr = ft_format_builder(newstr, fmt, total_len);
	newstr = ft_set_start(newstr, fmt, total_len, raw);
	return (newstr);
}
