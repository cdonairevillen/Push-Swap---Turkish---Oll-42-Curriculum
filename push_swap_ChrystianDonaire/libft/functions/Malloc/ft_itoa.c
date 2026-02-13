/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:10:38 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/02 17:10:54 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_len(int n)
{
	int		arr_len;

	arr_len = 0;
	if (n <= 0)
		arr_len++;
	while (n != 0)
	{
		n = n / 10;
		arr_len++;
	}
	return (arr_len);
}

char	*ft_itoa(int n)
{
	size_t		arr_len;
	char		*new_arr;
	long int	nb;

	arr_len = ft_check_len(n);
	new_arr = (char *)malloc((arr_len + 1) * sizeof(char));
	nb = (long int)n;
	if (!new_arr)
		return (NULL);
	new_arr[arr_len] = '\0';
	if (nb < 0)
	{
		new_arr[0] = '-';
		nb *= (-1);
	}
	if (nb == 0)
		new_arr[0] = '0';
	while (nb > 0)
	{
		arr_len--;
		new_arr[arr_len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (new_arr);
}
