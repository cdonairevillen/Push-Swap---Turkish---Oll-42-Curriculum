/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:06:00 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/14 14:06:04 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_var	fmt;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			fmt = ft_parse_format(&str);
			count += ft_print_format(fmt, ap);
		}
		else
		{
			count += ft_putchar_print(*str, 1);
			str++;
		}
	}
	va_end (ap);
	return (count);
}

/*int	main()
{
	char *c = "Holamundo";
	ft_printf(" NULL %p NULL", c);
	printf(" NULL %p NULL", c);
}*/
