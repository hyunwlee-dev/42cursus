/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:38:29 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 18:42:21 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_deque(t_deque_s *s_deque, char *s)
{
	char	*peeked_s;

	if (s_deque->size == 0)
	{
		add_rear_s(s_deque, s);
		return ;
	}
	peeked_s = find_left_list_s(s_deque);
	if (check_optimization_case(peeked_s, s))
		delete_rear_s(s_deque);
	else
		add_rear_s(s_deque, s);
}

int	treat_deque_size_zero_one_in_delete(t_deque *deque)
{
	int	value;

	value = 0;
	if (deque->size == 0)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
	else if (deque->size == 1)
	{
		value = deque->head->value;
		free(deque->head);
		deque->head = NULL;
		deque->tail = NULL;
	}
	return (value);
}

char	*treat_deque_size_zero_one_in_delete_s(t_deque_s *deque)
{
	char	*s;

	s = NULL;
	if (deque->size == 0)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
	else if (deque->size == 1)
	{
		s = deque->head->s;
		free(deque->head);
		deque->head = NULL;
		deque->tail = NULL;
	}
	return (s);
}
