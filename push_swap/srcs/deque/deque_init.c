/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:44:41 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 18:27:56 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_total(t_deques *dq, int argc, char **argv)
{
	init_deques_s(&dq->s_deque);
	if (init_deques(&dq->a_deque, &dq->b_deque, argc, argv))
	{
		clear(dq);
		ft_putstr("ERROR\n");
		return (-1);
	}
	return (0);
}

int	init_deques(t_deque *a_deque, t_deque *b_deque, int argc, char **argv)
{
	a_deque->head = NULL;
	a_deque->tail = NULL;
	a_deque->size = 0;
	b_deque->head = NULL;
	b_deque->tail = NULL;
	b_deque->size = 0;
	if (argc == 2 && (int)get_len(argv[1], ' ') > 1)
	{
		if (fill_deque_envp(a_deque, argv))
			return (-1);
		return (0);
	}
	if (fill_deque_general(a_deque, argc, argv))
		return (-1);
	return (0);
}

void	init_deques_s(t_deque_s *s_deque)
{
	s_deque->head = NULL;
	s_deque->tail = NULL;
	s_deque->size = 0;
}

int	fill_deque_envp(t_deque *a_deque, char **argv)
{
	int		idx;
	char	**temp;

	idx = 0;
	temp = ft_split(argv[1], ' ');
	if (check_integer(temp, (int)get_len(argv[1], ' '), -1) \
			|| check_integer_range(temp, (int)get_len(argv[1], ' '), -1))
		return (-1);
	while (idx < (int)get_len(argv[1], ' '))
		if (add_rear(a_deque, ft_atoi(temp[idx++])))
			return (-1);
	free_splited(temp, (int)get_len(argv[1], ' '));
	return (0);
}

int	fill_deque_general(t_deque *a_deque, int argc, char **argv)
{
	int	idx;

	idx = 0;
	while (++idx < argc)
	{
		if (check_integer(argv, argc, 0) || check_integer_range(argv, argc, 0))
			return (-1);
		if (add_rear(a_deque, ft_atoi(argv[idx])))
			return (-1);
	}
	return (0);
}
