/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:30:12 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/16 17:42:54 by hyunwlee         ###   ########.fr       */
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
// void	ra(t_deque *a_deque)
// {
// 	if (is_empty(a_deque))
// 	{
// 		// perror("IS_EMPTY ERROR");
// 		exit(1);
// 	}

// 	a_deque->tail->r_link = a_deque->head;
// 	a_deque->head = a_deque->head->l_link;
// 	a_deque-
// 	// // 1. 기존의 head의 r_link는 새로운 head가 된다.
// 	// a_deque->head = a_deque->head->r_link;
// 	// // 1-1 새로운 head의 l_link는 NULL가 된다.
// 	// a_deque->head->l_link = NULL;
// 	// // 1-2 새로운 head의 r_link는 그대로 둔다.
// 	// // 2.
// 	// // 기존의 tail의 l_link는 그대로 놔둔다.
// 	// // 기존의 tail의 r_link는 기존의 head가 된다.
// 	// // 기존의 head는 기존의 tail이 된다.
// 	// a_deque->head = a_deque->head->r_link;
// }
// /**
//  *	rb : rotate b
//  *
//  *	b 스택에 있는 모든 요소를 1씩 올린다 (첫번째는 맨 뒤로)
//  */
// void	rb(t_deque *a, t_deque *b)
// {

// }
// /**
//  *	rr : rotate a & rotate b
//  *
//  *	ra와 rb를 동시에
//  */
// void	rr(t_deque *a, t_deque *b)
// {
//
// }
// ///////////////////////////////////////////////////////////
// ////////////////////////   4️⃣   ///////////////////////////
// ///////////////////////////////////////////////////////////
// /**
//  *	rra : reverse rotate a
//  *
//  *	a 스택의 모든 요소를 1씩 내린다. (마지막은 맨위로)
//  */
// void	rra(t_deque *a, t_deque *b)
// {

// }
// /**
//  *	rrb : reverse rotate b
//  *
//  *	b 스택의 모든 요소를 1씩 내린다. (마지막은 맨위로)
//  */
// void	rrb(t_deque *a, t_deque *b)
// {

// }
// /**
//  *	rrr : reverse rotate a & reverse rotate b
//  *
//  *	rra와 rrb를 동시에
//  */
// void	rrr(t_deque *a, t_deque *b)
// {

// }
