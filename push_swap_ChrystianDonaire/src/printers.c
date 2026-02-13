/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:26:59 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/22 16:27:00 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pl(t_pile *a, t_pile *b, int flag)
{
	int	bsize_a;
	int	bsize_b;

	bsize_a = a->size;
	bsize_b = b->size;
	push_list(a, b);
	if (flag == 1)
		ft_printf("pb\n");
	else if (flag == 2)
		ft_printf("pa\n");
}

void	rl(t_pile *a, t_pile *b, int flag)
{
	if (flag == 1)
	{
		rotate_list(a);
		ft_printf("ra\n");
	}
	else if (flag == 2)
	{
		rotate_list(b);
		ft_printf("rb\n");
	}
	else if (flag == 3)
	{
		rotate_list(a);
		rotate_list(b);
		ft_printf("rr\n");
	}
}

void	rrl(t_pile *a, t_pile *b, int flag)
{
	if (flag == 1)
	{
		reverse_rotate_list(a);
		ft_printf("rra\n");
	}
	else if (flag == 2)
	{
		reverse_rotate_list(b);
		ft_printf("rrb\n");
	}
	else if (flag == 3)
	{
		reverse_rotate_list(a);
		reverse_rotate_list(b);
		ft_printf("rrr\n");
	}
}

void	sl(t_pile *a, t_pile *b, int flag)
{
	if (flag == 1)
	{
		swap_list(a);
		ft_printf("sa\n");
	}
	else if (flag == 2)
	{
		swap_list(b);
		ft_printf("sb\n");
	}
	else if (flag == 3)
	{
		swap_list(a);
		swap_list(b);
		ft_printf("ss\n");
	}
}
