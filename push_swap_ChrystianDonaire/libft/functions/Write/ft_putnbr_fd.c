/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:43:47 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/03 14:45:04 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char		mod;
	long int	n;

	mod = 0;
	n = (long int)nb;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = n * (-1);
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		mod = (n % 10);
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(mod, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
