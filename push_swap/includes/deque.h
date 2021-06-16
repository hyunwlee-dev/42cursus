/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:11:09 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/16 21:22:15 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include <stdlib.h>
# include "libft.h"

typedef struct	s_node
{
	int	value;
	struct s_node	*l_link;
	struct s_node	*r_link;
}				t_node;

typedef struct	s_deque
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}				t_deque;

void    init_deques(t_deque *a_deque, t_deque *b_deque);
t_node  *creat_node(t_node *l_link, t_node *r_link, int value);
int     add_front(t_deque *deque, int value);
int     add_rear(t_deque *deque, int value);
int		delete_front(t_deque *deque);
int		delete_rear(t_deque *deque);
int		get_front(t_deque *deque);
int		get_rear(t_deque *deque);
void    clear(t_deque *a_deque, t_deque *b_deque);

#endif
