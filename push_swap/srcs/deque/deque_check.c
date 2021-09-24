/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:42:42 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 18:23:43 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_integer(char **input, int input_len, int start_idx)
{
	int	i;
	int	j;
	int	minus_cnt;
	int	result;

	i = start_idx;
	result = 0;
	while (++i < input_len)
	{
		j = -1;
		minus_cnt = 0;
		while (input[i][++j] != '\0')
		{
			if (!(ft_isdigit(input[i][j]) || input[i][j] == '-'))
				result = -1;
			if (input[i][j] == '-')
				++minus_cnt;
		}
		if (minus_cnt > 1)
			result = -1;
	}
	return (result);
}

int	check_integer_range(char **input, int input_len, int start_idx)
{
	int	i;

	i = start_idx;
	while (++i < input_len)
	{
		if (input[i][0] == '-')
		{
			if (ft_strlen(input[i]) > 11)
				return (-1);
			if (ft_strlen(input[i]) == 11)
				if (check_integer_range_compare(input, i, 1))
					return (-1);
		}
		else
		{
			if (ft_strlen(input[i]) > 10)
				return (-1);
			if (ft_strlen(input[i]) == 10)
				if (check_integer_range_compare(input, i, 0))
					return (-1);
		}
	}
	return (0);
}

int	check_integer_range_compare(char **input, int idx, int is_minus)
{
	const char	*integer_min = "-2147483648";
	const char	*integer_max = "2147483647";
	int			i;
	int			result;

	result = 0;
	i = is_minus;
	while (input[idx][++i] != '\0')
	{
		if (is_minus == 1)
		{
			if (integer_min[i] < input[idx][i])
				result = -1;
		}
		else
		{
			if (integer_max[i] < input[idx][i])
				result = -1;
		}
	}
	return (result);
}

int	check_duplication_or_sorted(t_deque *a_deque)
{
	t_node	*node_i;
	int		idx;
	int		is_sorted;

	node_i = a_deque->head;
	idx = 0;
	is_sorted = 1;
	while (idx < a_deque->size)
	{
		if (rotate_list(a_deque, node_i->value, idx + 1, &is_sorted))
			return (1);
		node_i = node_i->r_link;
		++idx;
	}
	if (is_sorted)
		return (2);
	return (0);
}

int	check_optimization_case(char *f, char *s)
{
	if (ft_strncmp(f, "sa", 4) == 0 && ft_strncmp(s, "sa", 4) == 0)
		return (1);
	else if (ft_strncmp(f, "sb", 4) == 0 && ft_strncmp(s, "sb", 4) == 0)
		return (1);
	else if (ft_strncmp(f, "ss", 4) == 0 && ft_strncmp(s, "ss", 4) == 0)
		return (1);
	else if (ft_strncmp(f, "pa", 4) == 0 && ft_strncmp(s, "pb", 4) == 0)
		return (1);
	else if (ft_strncmp(f, "pb", 4) == 0 && ft_strncmp(s, "pa", 4) == 0)
		return (1);
	else if (ft_strncmp(f, "ra", 4) == 0 && ft_strncmp(s, "rra", 4) == 0)
		return (1);
	else if (ft_strncmp(f, "rra", 4) == 0 && ft_strncmp(s, "ra", 4) == 0)
		return (1);
	else if (ft_strncmp(f, "rb", 4) == 0 && ft_strncmp(s, "rrb", 4) == 0)
		return (1);
	else if (ft_strncmp(f, "rrb", 4) == 0 && ft_strncmp(s, "rb", 4) == 0)
		return (1);
	else if (ft_strncmp(f, "rr", 4) == 0 && ft_strncmp(s, "rrr", 4) == 0)
		return (1);
	else if (ft_strncmp(f, "rrr", 4) == 0 && ft_strncmp(s, "rr", 4) == 0)
		return (1);
	return (0);
}
