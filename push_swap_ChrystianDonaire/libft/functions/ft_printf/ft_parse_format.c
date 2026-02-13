/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:06:00 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/14 14:06:04 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_vars(const char **str)
{
	unsigned long	res;

	res = 0;
	while (**str >= '0' && **str <= '9')
	{
		res = res * 10 + (**str - '0');
		(*str)++;
	}
	return (res);
}

static t_var	ft_check_vars(t_var format, const char **str)
{
	if (**str >= '0' && **str <= '9')
		format.width = ft_atoi_vars(str);
	if (**str == '.')
	{
		format.point = 1;
		(*str)++;
		format.precision = ft_atoi_vars(str);
	}
	if ((**str >= 'a' && **str <= 'z')
		|| (**str >= 'A' && **str <= 'Z') || **str == '%')
	{
		format.type = **str;
		(*str)++;
	}
	return (format);
}

static t_var	ft_check_flag(t_var format, const char **str)
{
	while (**str == '-' || **str == '0' || **str == ' '
		|| **str == '+' || **str == '#')
	{
		if (**str == '-')
			format.minus = 1;
		else if (**str == '0')
			format.zero = 1;
		else if (**str == ' ')
			format.space = 1;
		else if (**str == '+')
			format.plus = 1;
		else if (**str == '#')
			format.hastag = 1;
		if (**str == '\0')
			return (format);
		(*str)++;
	}
	format = ft_check_vars(format, str);
	return (format);
}

t_var	ft_parse_format(const char **str)
{
	t_var	format;

	format.minus = 0;
	format.zero = 0;
	format.width = 0;
	format.point = 0;
	format.precision = -1;
	format.hastag = 0;
	format.space = 0;
	format.plus = 0;
	format.type = 0;
	format.sign = 0;
	(*str)++;
	format = ft_check_flag(format, str);
	return (format);
}
