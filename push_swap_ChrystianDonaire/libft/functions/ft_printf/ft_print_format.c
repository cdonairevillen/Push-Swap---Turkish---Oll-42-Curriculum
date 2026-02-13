/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:06:00 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/14 14:06:04 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_raw(t_var *fmt, va_list ap, char *raw)
{
	if (fmt->type == 'd' || fmt->type == 'i')
		raw = ft_writenbr_base(va_arg(ap, int), fmt);
	else if (fmt->type == 's')
		raw = ft_strdup(va_arg(ap, char *));
	else if (fmt->type == 'c')
		raw = ft_writechar(va_arg(ap, int));
	else if (fmt->type == 'p')
		raw = ft_write_pointer(va_arg(ap, unsigned long));
	else if (fmt->type == 'x' || fmt->type == 'X' || fmt->type == 'u')
		raw = ft_writenbr_base(va_arg(ap, unsigned int), fmt);
	else if (fmt->type == '%')
		raw = ft_writechar('%');
	else
		raw = ft_writechar(fmt->type);
	return (raw);
}

static char	*ft_apply_prec(char *raw, t_var fmt)
{
	char	*tmp;
	int		total;

	if (fmt.point == 0 || fmt.precision <= 0)
		return (raw);
	if (fmt.precision <= ft_strlen(raw))
		return (raw);
	total = fmt.precision;
	tmp = malloc((total + 1) * sizeof(char));
	if (!tmp)
		return (raw);
	ft_memset(tmp, '0', total - ft_strlen(raw));
	ft_memcpy(tmp + (total - ft_strlen(raw)), raw, ft_strlen(raw) + 1);
	free (raw);
	return (tmp);
}

int	ft_print_format(t_var fmt, va_list ap)
{
	char	*raw;
	char	*final;
	int		len;

	len = 0;
	raw = NULL;
	raw = ft_fill_raw(&fmt, ap, raw);
	if (!raw)
		return (0);
	if (raw[0] == '\0' && fmt.type == 'c')
	{
		ft_putchar_print(raw[0], 1);
		free (raw);
		return (1);
	}
	raw = ft_apply_prec(raw, fmt);
	final = ft_apply_sign(raw, fmt);
	len += ft_putstr_print(final, 1);
	if (!final)
		return (0);
	free (raw);
	free (final);
	return (len);
}
