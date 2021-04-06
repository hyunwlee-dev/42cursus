/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:41:00 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/04/06 19:01:50 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

#include <stdlib.h>

typedef struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct	s_node
{
	t_position		pos;
	struct s_node	*next;
}				t_node;

typedef struct	s_queue
{
	t_node	*front;
	t_node	*rear;
}				t_queue;

int			is_empty(t_queue *q);
void	offer(t_queue *q, t_position p);
t_position	poll(t_queue *q);
void		free_q(t_queue *q);

#endif
