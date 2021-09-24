/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:41:43 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 18:38:56 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_list(t_deque *a_deque, int node_i_value, int cnt, int *is_sorted)
{
	t_node	*node_j;
	int		jdx;

	node_j = a_deque->head;
	jdx = -1;
	while (++jdx < cnt)
		node_j = node_j->r_link;
	while (jdx < a_deque->size)
	{
		if (node_i_value == node_j->value)
			return (-1);
		if (node_i_value > node_j->value)
			*is_sorted = 0;
		node_j = node_j->r_link;
		++jdx;
	}
	return (0);
}

char	*find_left_list_s(t_deque_s *deque)
{
	t_node_s	*node;
	int			idx;

	idx = -1;
	node = deque->head;
	while (++idx < deque->size - 1)
		node = node->r_link;
	return (node->s);
}

void	free_splited(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
}
