/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:58:41 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/06 15:59:00 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include "libft.h"

//----------------//JUST TO CHECK//-----------------//
# include <stdio.h>
//----------------//JUST TO CHECK//-----------------//

typedef struct s_node
{
	int				content;
	int				id;
	int				cost_a;
	int				cost_b;
	int				lis;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_pile
{
	t_node			*top;
	t_node			*bot;
	int				size;
}	t_pile;

void	set_numbers(t_node *list);
void	set_index(t_node *list);
void	find_lis(t_pile *a);
//----------------//Input//-----------------//
int		parse_args(int argc, char **argv, t_node **list);
t_node	*ft_lstnew_fix(int num);
void	ft_lstadd_back_fix(t_node **lst, t_node *new);
int		compare_nodes(t_node *list, int num);
int		only_spaces(char *s);
//-----------//Sort Functions//-------------//
void	sort_numbers(t_pile *a, t_pile *b);
void	calculate_costs(t_pile *a, t_pile *b);
int		move_node(t_pile *a, t_pile *b, t_node *best);
int		is_sorted(t_pile *pile);
void	sort_little(t_pile *a, t_pile *b);
int		swap_list(t_pile *pile);
int		push_list(t_pile *pile_a, t_pile *pile_b);
int		rotate_list(t_pile *pile);
int		reverse_rotate_list(t_pile *pile);
void	pl(t_pile *a, t_pile *b, int flag);
void	rl(t_pile *a, t_pile *b, int flag);
void	rrl(t_pile *a, t_pile *b, int flag);
void	sl(t_pile *a, t_pile *b, int flag);
//----------------//Utils//-----------------//
void	free_for_all(t_node **lst);
void	check_if_loop(t_node *temp, t_node *node, t_pile *a);
long	ft_atol(char *str);
void	free_elems(char **elem);
int		ft_abs(int num);

#endif