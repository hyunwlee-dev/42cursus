/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:40:00 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 18:36:06 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node_s	*creat_node_s(t_node_s *l_link, t_node_s *r_link, char *s, int idx)
{
	t_node_s	*node;

	node = (t_node_s *)malloc(sizeof(t_node_s));
	if (!node)
		return (NULL);
	node->idx = idx;
	node->s = s;
	node->l_link = l_link;
	node->r_link = r_link;
	return (node);
}

void	add_rear_s(t_deque_s *deque, char *s)
{
	t_node_s	*new_node;

	new_node = creat_node_s(deque->tail, deque->head, s, deque->size);
	if (!new_node)
		exit(1);
	if (!deque->size)
	{
		deque->head = new_node;
		deque->tail = new_node;
	}
	else
	{
		deque->tail->r_link = new_node;
		deque->tail = new_node;
		deque->head->l_link = deque->tail;
	}
	++deque->size;
}

char	*delete_rear_s(t_deque_s *deque)
{
	t_node_s	*removed_node;
	char		*s;

	if (deque->size == 0 || deque->size == 1)
		s = treat_deque_size_zero_one_in_delete_s(deque);
	else
	{
		removed_node = deque->tail;
		s = removed_node->s;
		deque->tail = deque->tail->l_link;
		free(removed_node);
		deque->head->l_link = deque->tail;
		deque->tail->r_link = deque->head;
	}
	--deque->size;
	return (s);
}

char	*get_front_s(t_deque_s *deque)
{
	if (!deque->size)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
	return (deque->head->s);
}

void	print_all_s(t_deque_s *deque)
{
	t_node_s	*node;
	int			idx;

	idx = -1;
	node = deque->head;
	while (++idx < deque->size)
	{
		ft_putstr(node->s);
		ft_putstr("\n");
		node = node->r_link;
	}
}
