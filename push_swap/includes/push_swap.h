/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:31:22 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/18 19:34:04 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "deque.h"

void	ft_putchar(char c);
void    ft_putstr(char *str);
void	ft_putnbr(int nb);

void 	quick_sort(t_deque *a_deque, t_deque *b_deque, int start, int end);

void	sa(t_deque *a_deque);
void	sb(t_deque *b_deque);
void	ss(t_deque *a, t_deque *b);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	ra(t_deque *a_deque);
void	rb(t_deque *b_deque);
void	rr(t_deque *a_deque, t_deque *b_deque);
void	rra(t_deque *a_deque);
void	rrb(t_deque *b_deque);
void	rrr(t_deque *a_deque, t_deque *b_deque);

#endif
