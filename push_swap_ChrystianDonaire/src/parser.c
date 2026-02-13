/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:36:23 by cdonaire          #+#    #+#             */
/*   Updated: 2025/11/23 16:36:24 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_real_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		len++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		len++;
	}
	return (len);
}

static int	is_valid_num(char *str)
{
	int	i;
	int	digits;

	i = 0;
	digits = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		digits++;
	}
	if (digits == 0)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static int	process_elem(char *elem, t_node **list)
{
	long	num;
	t_node	*new;

	num = ft_atol(elem);
	if (check_real_len(elem) > 11)
		return (write(2, "Error\n", 7), 0);
	if (!is_valid_num(elem))
		return (write(2, "Error\n", 7), 0);
	if (num < INT_MIN || num > INT_MAX)
		return (write(2, "Error\n", 7), 0);
	if (!compare_nodes(*list, num))
		return (write(2, "Error\n", 7), 0);
	new = ft_lstnew_fix(num);
	if (!new)
		return (0);
	ft_lstadd_back_fix(list, new);
	return (1);
}

static char	**split_if_string(char *argv)
{
	int		i;
	char	**out;

	i = 0;
	if (only_spaces(argv))
		return (NULL);
	while (argv[i])
	{
		if (argv[i] == ' ')
			return (ft_split(argv, ' '));
		i++;
	}
	out = malloc(sizeof(char *) * 2);
	if (!out)
		return (NULL);
	out[0] = ft_strdup(argv);
	out[1] = NULL;
	return (out);
}

int	parse_args(int argc, char **argv, t_node **list)
{
	int		i;
	int		j;
	char	**elem;

	i = 1;
	while (i < argc)
	{
		elem = split_if_string(argv[i]);
		if (!elem || !elem[0])
			return (write(2, "Error\n", 7), 0);
		j = 0;
		while (elem[j])
		{
			if (!process_elem(elem[j], list))
				return (free_elems(elem), free_for_all(list), 0);
			j++;
		}
		free_elems(elem);
		i++;
	}
	return (1);
}
