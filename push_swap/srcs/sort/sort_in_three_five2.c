/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_three_five2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:09:38 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 18:57:55 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort_id_in_three_five(t_sort_id_three_five *sort_id)
{
	sort_id->node = NULL;
	sort_id->min = 2147483647;
	sort_id->max = -2147483648;
	sort_id->min_idx = 0;
	sort_id->max_idx = 0;
}

void	find_min_max_idx_in_three_five(t_deque *a_deque, \
		t_sort_id_three_five *sort_id)
{
	int	idx;

	idx = -1;
	sort_id->node = a_deque->head;
	while (++idx < a_deque->size)
	{
		if (sort_id->min > sort_id->node->value)
		{
			sort_id->min = sort_id->node->value;
			sort_id->min_idx = sort_id->node->idx;
		}
		if (sort_id->max < sort_id->node->value)
		{
			sort_id->max = sort_id->node->value;
			sort_id->max_idx = sort_id->node->idx;
		}
		sort_id->node = sort_id->node->r_link;
	}
}
