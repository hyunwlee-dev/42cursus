/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:30:12 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/07/30 18:31:36 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
///////////////////////////////////////////////////////////
////////////////////////   1️⃣   ///////////////////////////
///////////////////////////////////////////////////////////
/**
 *	sa : swap a
 *
 *	a 스택 맨위에 있는 처음 2개 요소를 바뀐다. (2 이상이여야 한다.)
 */
void	sa(t_deque *a_deque)
{
	int	first_value;
	int	second_value;

	first_value = delete_front(a_deque);
	second_value = delete_front(a_deque);
	add_front(a_deque , first_value);
	add_front(a_deque , second_value);
}
/**
 *	sb : swap b
 *
 *	b 스택 맨위에 있는 처음 2개 요소를 바뀐다. (2 이상이여야 한다.)
 */
void	sb(t_deque *b_deque)
{
	int	first_value;
	int	second_value;

	first_value = delete_front(b_deque);
	second_value = delete_front(b_deque);
	add_front(b_deque , first_value);
	add_front(b_deque , second_value);
}
/**
 *	ss : swap a & swap b
 *
 *	sa와 sb를 동시에
 */
void	ss(t_deque *a_deque, t_deque *b_deque)
{
	sa(a_deque);
	sb(b_deque);
}
///////////////////////////////////////////////////////////
////////////////////////   2️⃣   ///////////////////////////
///////////////////////////////////////////////////////////
/**
 *	pa : push a
 *
 *	b의 상단에 있는 첫번째 요소를 가져와서 a상단에 배치 (b is not empty)
 */
void	pa(t_deque *a_deque, t_deque *b_deque)
{
	add_front(a_deque, delete_front(b_deque));
}
/**
 *	pb : push b
 *
 *	a의 상단에 있는 첫번째 요소를 가져와서 b상단에 배치 (a is not empty)
 */
void	pb(t_deque *a_deque, t_deque *b_deque)
{
	add_front(b_deque, delete_front(a_deque));
}
// ///////////////////////////////////////////////////////////
// ////////////////////////   3️⃣   ///////////////////////////
// ///////////////////////////////////////////////////////////
/**
 *	ra : rotate a
 *
 *	a 스택에 있는 모든 요소를 1씩 올린다 (첫번째는 맨 뒤로)
 */
void	ra(t_deque *a_deque)            // ra, rb, rra, rrb 에서 idx 정렬시키는거 따로 함수 빼자 나중에
{
    a_deque->head = a_deque->head->r_link;
    a_deque->tail = a_deque->head->l_link;
}

void    retreat_idx(t_deque *a_deque, t_deque *b_deque)
{
    int idx;
    t_node *node;

    idx = 0;
    node = a_deque->head;
    while (idx < a_deque->size)
    {
        node->idx = idx++;
        node = node->r_link;
    }
    idx = 0;
    node = b_deque->head;
    while (idx < b_deque->size)
    {
        node->idx = idx++;
        node = node->r_link;
    }
}

void	rb(t_deque *b_deque)
{
    b_deque->head = b_deque->head->r_link;
    b_deque->tail = b_deque->head->l_link;
}

void	rr(t_deque *a_deque, t_deque *b_deque)
{
    ra(a_deque);
    rb(b_deque);
}
// ///////////////////////////////////////////////////////////
// ////////////////////////   4️⃣   ///////////////////////////
// ///////////////////////////////////////////////////////////
void	rra(t_deque *a_deque)
{
    a_deque->head = a_deque->head->l_link;
    a_deque->tail = a_deque->head->l_link;
}

void	rrb(t_deque *b_deque)
{
    b_deque->head = b_deque->head->l_link;
    b_deque->tail = b_deque->head->l_link;
}

void	rrr(t_deque *a_deque, t_deque *b_deque)
{
    rra(a_deque);
    rrb(b_deque);
}
