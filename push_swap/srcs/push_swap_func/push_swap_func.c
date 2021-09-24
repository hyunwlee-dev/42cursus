/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:30:12 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/22 18:17:01 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a_deque, t_deque_s *s_deque)
{
	int	first_value;
	int	second_value;

	first_value = delete_front(a_deque);
	second_value = delete_front(a_deque);
	add_front(a_deque, first_value);
	add_front(a_deque, second_value);
	optimize_deque(s_deque, "sa");
}

void	sb(t_deque *b_deque, t_deque_s *s_deque)
{
	int	first_value;
	int	second_value;

	first_value = delete_front(b_deque);
	second_value = delete_front(b_deque);
	add_front(b_deque, first_value);
	add_front(b_deque, second_value);
	optimize_deque(s_deque, "sb");
}

void	ss(t_deque *a_deque, t_deque *b_deque, t_deque_s *s_deque)
{
	int	first_value;
	int	second_value;

	first_value = delete_front(a_deque);
	second_value = delete_front(a_deque);
	add_front(a_deque, first_value);
	add_front(a_deque, second_value);
	first_value = delete_front(b_deque);
	second_value = delete_front(b_deque);
	add_front(b_deque, first_value);
	add_front(b_deque, second_value);
	optimize_deque(s_deque, "ss");
}

void	pa(t_deque *a_deque, t_deque *b_deque, t_deque_s *s_deque)
{
	add_front(a_deque, delete_front(b_deque));
	optimize_deque(s_deque, "pa");
}

void	pb(t_deque *a_deque, t_deque *b_deque, t_deque_s *s_deque)
{
	add_front(b_deque, delete_front(a_deque));
	optimize_deque(s_deque, "pb");
}
