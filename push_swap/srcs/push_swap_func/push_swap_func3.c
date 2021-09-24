/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:30:12 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/22 18:16:01 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_deque *a_deque, t_deque *b_deque, t_deque_s *s_deque)
{
	if (a_deque->size == 1 && b_deque->size == 1)
		return ;
	else if (a_deque->size == 1)
	{
		rrb(b_deque, s_deque);
		return ;
	}
	else if (b_deque->size == 1)
	{
		rra(a_deque, s_deque);
		return ;
	}
	a_deque->head = a_deque->head->l_link;
	a_deque->tail = a_deque->head->l_link;
	b_deque->head = b_deque->head->l_link;
	b_deque->tail = b_deque->head->l_link;
	optimize_deque(s_deque, "rrr");
}
