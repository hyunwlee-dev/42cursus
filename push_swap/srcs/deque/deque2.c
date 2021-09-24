/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:49:19 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 17:45:14 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_front(t_deque *deque)
{
	if (!deque->size)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
	return (deque->head->value);
}

int	get_rear(t_deque *deque)
{
	if (!deque->size)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
	return (deque->tail->value);
}

void	clear(t_deques *dq)
{
	while (dq->a_deque.size)
		delete_front(&dq->a_deque);
	while (dq->b_deque.size)
		delete_front(&dq->a_deque);
	clear_s(&dq->s_deque);
}

void	clear_s(t_deque_s *deque)
{
	while (deque->size)
		delete_rear_s(deque);
}

void	print_all(t_deque *deque)
{
	t_node	*node;
	int		idx;

	node = deque->head;
	idx = -1;
	ft_putstr("===============================\n");
	while (++idx < deque->size)
	{
		ft_putstr("idx: ");
		ft_putnbr(node->idx);
		ft_putstr("\t");
		ft_putstr("value: ");
		ft_putnbr(node->value);
		ft_putstr("\n");
		node = node->r_link;
	}
	ft_putstr("===============================\n");
}
