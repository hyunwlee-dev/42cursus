/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:14:42 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 18:49:21 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_validation(t_deques *dq)
{
	int	check_case;

	check_case = 0;
	check_case = check_duplication_or_sorted(&dq->a_deque);
	if (check_case > 0)
	{
		if (check_case == 1)
			ft_putstr("ERROR\n");
		clear(dq);
		return (-1);
	}
	return (0);
}

int	check_escape_condition_a_to_b(t_deques *dq, int range)
{
	if (range < 3)
	{
		if (range == 2)
			sort_two_elements(&dq->a_deque, &dq->s_deque);
		return (1);
	}
	return (0);
}

int	check_escape_condition_b_to_a(t_deques *dq, int range)
{
	if (range < 3)
	{
		if (range == 2)
			sort_two_elements_reverse_order(&dq->b_deque, &dq->s_deque);
		while (range-- > 0)
			pa(&dq->a_deque, &dq->b_deque, &dq->s_deque);
		return (1);
	}
	return (0);
}
