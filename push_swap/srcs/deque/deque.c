/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:30:40 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/16 18:42:00 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h> // 나중에 삭제 해주자.

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

 /**
  *	 init 처리 해주자
  */
int		is_empty(t_deque *deque)
{
	return (deque->size == 0);
}

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

void	add_front(t_deque *deque, int value)
{
	t_node *new_node = creat_node(deque->tail, deque->head, value);
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
}

void	add_rear(t_deque *deque, int value)
{
	t_node *new_node = creat_node(deque->tail, deque->head, value);
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

/**
 *	rear일때 size의 경우는 3가지 head와 tail를 NULL로 처리하기 위해서
 */
int		delete_front(t_deque *deque)
{
	t_node 	*removed_node;
    int     value;

    value = 0;
	if (deque->size == 0)
	{
		perror("IS_EMPTY ERROR");
		exit(1);
	}
   else if (deque->size == 1)
   {
        value = deque->head->value;
        free(deque->head);
        deque->head = NULL;
        deque->tail = NULL;
   }
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

int		delete_rear(t_deque *deque)
{
	t_node 	*removed_node;
	int 	value;

    value = 0;
	if (!deque->size)
	{
		perror("IS_EMPTY ERROR");
		exit(1);
	}
    else if (deque->size == 1)
    {
        value = deque->head->value;
        free(deque->head);
        deque->head = NULL;
        deque->tail = NULL;
    }
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

int		get_front(t_deque *deque)
{
	if (!deque->size)
	{
		perror("IS_EMPTY ERROR");
		exit(1);
	}
	return (deque->head->value);
}

int		get_rear(t_deque *deque)
{
	if (!deque->size)
	{
		perror("IS_EMPTY ERROR");
		exit(1);
	}
	return (deque->tail->value);
}
