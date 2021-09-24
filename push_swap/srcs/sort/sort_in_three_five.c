/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_three_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:08:25 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 18:55:10 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	treat_deque_size_three_five(t_deques *dq)
{
	if (dq->a_deque.size == 3)
	{
		sort_three_elements(&dq->a_deque, &dq->s_deque);
		return (1);
	}
	else if (dq->a_deque.size == 5)
	{
		sort_five_elements(&dq->a_deque, &dq->b_deque, &dq->s_deque);
		return (1);
	}
	return (0);
}

void	sort_two_elements(t_deque *deque, t_deque_s *s_deque)
{
	int	first;
	int	second;

	first = deque->head->value;
	second = deque->head->r_link->value;
	if (first > second)
		sa(deque, s_deque);
}

void	sort_two_elements_reverse_order(t_deque *deque, t_deque_s *s_deque)
{
	int	first;
	int	second;

	first = deque->head->value;
	second = deque->head->r_link->value;
	if (first < second)
		sb(deque, s_deque);
}

void	sort_three_elements(t_deque *a_deque, t_deque_s *s_deque)
{
	t_sort_id_three_five	sort_id;

	init_sort_id_in_three_five(&sort_id);
	find_min_max_idx_in_three_five(a_deque, &sort_id);
	if (sort_id.min_idx == 0 && sort_id.max_idx == 1)
	{
		sa(a_deque, s_deque);
		ra(a_deque, s_deque);
	}
	else if (sort_id.min_idx == 1 && sort_id.max_idx == 0)
		ra(a_deque, s_deque);
	else if (sort_id.min_idx == 1 && sort_id.max_idx == 2)
		sa(a_deque, s_deque);
	else if (sort_id.min_idx == 2 && sort_id.max_idx == 0)
	{
		sa(a_deque, s_deque);
		rra(a_deque, s_deque);
	}
	else if (sort_id.min_idx == 2 && sort_id.max_idx == 1)
		rra(a_deque, s_deque);
}

void	sort_five_elements(t_deque *a_deque, t_deque *b_deque, \
		t_deque_s *s_deque)
{
	t_sort_id_three_five	sort_id;
	int						idx;

	init_sort_id_in_three_five(&sort_id);
	find_min_max_idx_in_three_five(a_deque, &sort_id);
	sort_id.node = a_deque->head;
	idx = -1;
	while (++idx < 5)
	{
		if (idx == sort_id.min_idx || idx == sort_id.max_idx)
			pb(a_deque, b_deque, s_deque);
		else
			ra(a_deque, s_deque);
	}
	retreat_idx(a_deque, b_deque);
	sort_three_elements(a_deque, s_deque);
	sort_two_elements_reverse_order(b_deque, s_deque);
	pa(a_deque, b_deque, s_deque);
	ra(a_deque, s_deque);
	pa(a_deque, b_deque, s_deque);
}
