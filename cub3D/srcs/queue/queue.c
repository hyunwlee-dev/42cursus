 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:35:58 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/01 17:34:17 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

int			is_empty(t_queue *q)
{
	return (q->front == 0);
}

void		offer(t_queue *q, t_position p)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
	{
		printf("ALLOCATION FAIL!!\n");
		return ;
	}
	new->pos.x = p.x;
	new->pos.y = p.y;
	new->next = NULL;
	if (is_empty(q))
	{
		q->front = new;
		q->rear = new;
	}
	else
	{
		q->rear->next = new;
		q->rear = new;
	}
}

t_position	poll(t_queue *q)
{
	t_node		*temp;
	t_position	pos;

	temp = q->front;
	pos.x = temp->pos.x;
	pos.y = temp->pos.y;
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	free(temp);
	return (pos);
}

void		free_q(t_queue *q)
{
	t_node *temp;

	while (q->front)
	{
		temp = q->front;
		q->front = q->front->next;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		temp = 0;
	}
}
