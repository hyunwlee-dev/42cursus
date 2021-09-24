/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:30:40 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 17:39:49 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*creat_node(t_node *l_link, t_node *r_link, int value, int idx)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->idx = idx;
	node->value = value;
	node->l_link = l_link;
	node->r_link = r_link;
	return (node);
}

int	add_front(t_deque *deque, int value)
{
	t_node	*new_node;

	new_node = creat_node(deque->tail, deque->head, value, deque->size);
	if (!new_node)
		return (-1);
	if (!deque->size)
	{
		deque->head = new_node;
		deque->tail = new_node;
	}
	else
	{
		deque->head->l_link = new_node;
		deque->head = new_node;
		deque->tail->r_link = deque->head;
	}
	++deque->size;
	return (0);
}

int	add_rear(t_deque *deque, int value)
{
	t_node	*new_node;

	new_node = creat_node(deque->tail, deque->head, value, deque->size);
	if (!new_node)
		return (-1);
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
	return (0);
}

int	delete_front(t_deque *deque)
{
	t_node	*removed_node;
	int		value;

	if (deque->size == 0 || deque->size == 1)
		value = treat_deque_size_zero_one_in_delete(deque);
	else
	{
		removed_node = deque->head;
		value = removed_node->value;
		deque->head = deque->head->r_link;
		free(removed_node);
		deque->tail->r_link = deque->head;
		deque->head->l_link = deque->tail;
	}
	--deque->size;
	return (value);
}

int	delete_rear(t_deque *deque)
{
	t_node	*removed_node;
	int		value;

	if (deque->size == 0 || deque->size == 1)
		value = treat_deque_size_zero_one_in_delete(deque);
	else
	{
		removed_node = deque->tail;
		value = removed_node->value;
		deque->tail = deque->tail->l_link;
		free(removed_node);
		deque->head->l_link = deque->tail;
		deque->tail->r_link = deque->head;
	}
	--deque->size;
	return (value);
}
