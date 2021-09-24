/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:06:31 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 19:03:10 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_sort_id(t_sort_id *sort_id, int range)
{
	sort_id->node = NULL;
	sort_id->pivot = (int *)malloc(sizeof(int) * 2);
	if (!sort_id->pivot)
		return (-1);
	sort_id->arr = (int *)malloc(sizeof(int) * range);
	if (!sort_id->arr)
		return (-1);
	sort_id->pa_cnt = 0;
	sort_id->pb_cnt = 0;
	sort_id->ra_cnt = 0;
	sort_id->rb_cnt = 0;
	sort_id->union_ra_rb_cnt = 0;
	sort_id->private_ra_cnt = 0;
	sort_id->private_rb_cnt = 0;
	return (0);
}

int	find_ra_rb_min(int ra_cnt, int rb_cnt)
{
	if (ra_cnt < rb_cnt)
		return (ra_cnt);
	else
		return (rb_cnt);
}

int	*find_pivots(t_deque *deque, t_sort_id *sort_id, int range)
{
	int	i;

	sort_id->node = deque->head;
	i = 0;
	while (i < range)
	{
		sort_id->arr[i++] = sort_id->node->value;
		sort_id->node = sort_id->node->r_link;
	}
	quick_sort(sort_id->arr, 0, range - 1);
	sort_id->pivot[0] = sort_id->arr[range * 2 / 3];
	sort_id->pivot[1] = sort_id->arr[range / 3];
	return (sort_id->pivot);
}

void	free_allocated_sort_id(t_sort_id *sort_id)
{
	free(sort_id->arr);
	free(sort_id->pivot);
	sort_id->pivot = 0;
	sort_id->arr = 0;
}

void	retreat_idx(t_deque *a_deque, t_deque *b_deque)
{
	int		idx;
	t_node	*node;

	idx = 0;
	node = a_deque->head;
	while (idx < a_deque->size)
	{
		node->idx = idx++;
		node = node->r_link;
	}
	idx = 0;
	node = b_deque->head;
	while (idx < b_deque->size)
	{
		node->idx = idx++;
		node = node->r_link;
	}
}
