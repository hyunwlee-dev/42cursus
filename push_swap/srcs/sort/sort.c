/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:20:46 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 18:48:07 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_deques *dq, int range)
{
	t_sort_id	sort_id;

	if (check_escape_condition_a_to_b(dq, range))
		return ;
	if (init_sort_id(&sort_id, range))
		exit(1);
	process_in_a_to_b(dq, &sort_id, range);
	sort_id.union_ra_rb_cnt = find_ra_rb_min(sort_id.ra_cnt, sort_id.rb_cnt);
	sort_id.private_ra_cnt = sort_id.ra_cnt - sort_id.union_ra_rb_cnt;
	sort_id.private_rb_cnt = sort_id.rb_cnt - sort_id.union_ra_rb_cnt;
	while (sort_id.union_ra_rb_cnt-- > 0)
		rrr(&dq->a_deque, &dq->b_deque, &dq->s_deque);
	while (sort_id.private_ra_cnt-- > 0)
		rra(&dq->a_deque, &dq->s_deque);
	while (sort_id.private_rb_cnt-- > 0)
		rrb(&dq->b_deque, &dq->s_deque);
	a_to_b(dq, sort_id.ra_cnt);
	b_to_a(dq, sort_id.rb_cnt);
	b_to_a(dq, sort_id.pb_cnt - sort_id.rb_cnt);
}

void	b_to_a(t_deques *dq, int range)
{
	t_sort_id	sort_id;

	if (check_escape_condition_b_to_a(dq, range))
		return ;
	if (init_sort_id(&sort_id, range))
		exit(1);
	process_in_b_to_a(dq, &sort_id, range);
	a_to_b(dq, sort_id.pa_cnt - sort_id.ra_cnt);
	sort_id.union_ra_rb_cnt = find_ra_rb_min(sort_id.ra_cnt, sort_id.rb_cnt);
	sort_id.private_ra_cnt = sort_id.ra_cnt - sort_id.union_ra_rb_cnt;
	sort_id.private_rb_cnt = sort_id.rb_cnt - sort_id.union_ra_rb_cnt;
	while (sort_id.union_ra_rb_cnt-- > 0)
		rrr(&dq->a_deque, &dq->b_deque, &dq->s_deque);
	while (sort_id.private_ra_cnt-- > 0)
		rra(&dq->a_deque, &dq->s_deque);
	while (sort_id.private_rb_cnt-- > 0)
		rrb(&dq->b_deque, &dq->s_deque);
	a_to_b(dq, sort_id.ra_cnt);
	b_to_a(dq, sort_id.rb_cnt);
}

void	process_in_a_to_b(t_deques *dq, t_sort_id *sort_id, int range)
{
	int	idx;
	int	*pivot;

	idx = 0;
	pivot = find_pivots(&dq->a_deque, sort_id, range);
	while (idx < range)
	{
		if (dq->a_deque.head->value >= pivot[0])
		{
			ra(&dq->a_deque, &dq->s_deque);
			++sort_id->ra_cnt;
		}
		else
		{
			pb(&dq->a_deque, &dq->b_deque, &dq->s_deque);
			++sort_id->pb_cnt;
			if (dq->b_deque.head->value >= pivot[1])
			{
				rb(&dq->b_deque, &dq->s_deque);
				++sort_id->rb_cnt;
			}
		}
		idx++;
	}
	free_allocated_sort_id(sort_id);
}

void	process_in_b_to_a(t_deques *dq, t_sort_id *sort_id, int range)
{
	int	idx;
	int	*pivot;

	idx = 0;
	pivot = find_pivots(&dq->b_deque, sort_id, range);
	while (idx < range)
	{
		if (dq->b_deque.head->value < pivot[1])
		{
			rb(&dq->b_deque, &dq->s_deque);
			++sort_id->rb_cnt;
		}
		else
		{
			pa(&dq->a_deque, &dq->b_deque, &dq->s_deque);
			++sort_id->pa_cnt;
			if (dq->a_deque.head->value < pivot[0])
			{
				ra(&dq->a_deque, &dq->s_deque);
				++sort_id->ra_cnt;
			}
		}
		idx++;
	}
	free_allocated_sort_id(sort_id);
}

void	sort(t_deques *dq)
{
	if (treat_deque_size_three_five(dq))
	{
		print_all_s(&dq->s_deque);
		clear(dq);
		return ;
	}
	a_to_b(dq, dq->a_deque.size);
	print_all_s(&dq->s_deque);
	clear(dq);
}
