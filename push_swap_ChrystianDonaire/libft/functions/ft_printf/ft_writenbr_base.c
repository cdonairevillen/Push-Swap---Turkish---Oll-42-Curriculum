/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:16:59 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/17 16:17:05 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_change_base(t_var fmt)
{
	if (fmt.type == 'x')
		return ("0123456789abcdef");
	if (fmt.type == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789");
}

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if ((base[i] == ' ') || (base[i] == '+')
			|| (base[i] == '-') || (base[i] >= 9 && base[i] <= 13))
			return (0);
		i++;
	}
	return (i);
}

static void	ft_check_sign(long *nbr, t_var *fmt)
{
	if (*nbr < 0 && (fmt->type == 'd' || fmt->type == 'i'))
	{
		*nbr = *nbr * (-1);
		fmt->sign = '-';
	}
	else
	{
		if (*nbr > 0 && fmt->plus)
			fmt->sign = '+';
		else if (*nbr > 0 && fmt->space)
			fmt->sign = ' ';
		else
			fmt->sign = 0;
	}
}

char	*ft_writenbr_base(long nbr, t_var *fmt)
{
	char	buff[65];
	char	neg;
	int		i;
	char	*base;
	int		baselen;

	i = 64;
	neg = 'f';
	base = ft_change_base(*fmt);
	baselen = ft_check_base(base);
	ft_check_sign(&nbr, fmt);
	if (baselen < 2)
		return (ft_strdup(""));
	buff[i--] = '\0';
	if (nbr == 0)
		buff[i--] = '0';
	while (nbr)
	{
		buff[i--] = base[nbr % baselen];
		nbr = nbr / baselen;
	}
	return (ft_strdup(&buff[i + 1]));
}
