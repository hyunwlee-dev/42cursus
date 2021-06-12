/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:30:40 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/12 18:15:13 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

/** deque 구현할 것
 --------------------------------------------------
 *	1. create();			덱 생성		(O)
 *	2. init(dq);			덱을 초기화
 *	3. is_empty(dq);
 *	4. is_full(dq);			포화 상태인지 (넣어야 하나??)
 --------------------------------------------------
 *	5. add_front(dq, e);
 *	6. add_rear(dq, e);
 *	7. delete_front(dq);
 *	8. delete_rear(dq);
 --------------------------------------------------
 *	9. get_front(q);
 * 10. get_rear(q);
 --------------------------------------------------
 */

t_node	*creat_node(t_node *l_link, t_node *r_link, int value)
{
	t_node *node;
	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	node->value = value;
	node->l_link = l_link;
	node->r_link = r_link;
	return (node);
}

int		is_empty(t_deque *deque)
{
	return (deque->head == NULL);
}

void	add_rear(t_deque *deque, int value)
{
	t_node *new_node = creat_node(deque->tail, NULL, value);
	if (is_empty(deque))
		deque->head = new_node;
	else
		deque->tail->r_link = new_node;
	deque->tail = new_node;
}

void	add_front(t_deque *deque, int value)
{
	t_node *new_node = creat_node(NULL, deque->head, value);
	if (is_empty(deque))
		deque->tail = new_node;
	else
		deque->head->l_link = new_node;
	deque->head = new_node;
}

int		delete_front(t_deque *deque)
{
	int 	value;
	t_node 	*removed_node;

	if (is_empty(deque))
		exit(1);
	else
	{
		removed_node = deque->head;
		value = removed_node->value;
		deque->head = deque->head->r_link;
		free(removed_node);
		if (deque->head == NULL)
			deque->tail = NULL;
		else
			deque->head->l_link = NULL;
	}
	return (value);
}

int		delete_rear(t_deque *deque)
{
	int 	value;
	t_node 	*removed_node;

	if (is_empty(deque))
		exit(1);
	else
	{
		removed_node = deque->tail;
		value = removed_node->value;
		deque->tail = deque->tail->l_link;
		free(removed_node);
		if (deque->tail == NULL)
			deque->head = NULL;
		else
			deque->tail->r_link = NULL;
	}
	return (value);
}
