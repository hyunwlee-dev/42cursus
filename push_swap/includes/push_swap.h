/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:31:22 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 23:23:27 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "deque.h"

typedef struct s_sort_id_three_five
{
	t_node	*node;
	int		min;
	int		max;
	int		min_idx;
	int		max_idx;
}	t_sort_id_three_five;

typedef struct s_sort_id
{
	t_node	*node;
	int		*pivot;
	int		*arr;
	int		ra_cnt;
	int		rb_cnt;
	int		pa_cnt;
	int		pb_cnt;
	int		union_ra_rb_cnt;
	int		private_ra_cnt;
	int		private_rb_cnt;
}	t_sort_id;

typedef struct s_quick_sort
{
	int	left;
	int	right;
	int	pivot;
	int	temp;
}	t_quick_sort;

void	sa(t_deque *a_deque, t_deque_s *s_deque);
void	sb(t_deque *b_deque, t_deque_s *s_deque);
void	ss(t_deque *a_deque, t_deque *b_deque, t_deque_s *s_deque);
void	pa(t_deque *a_deque, t_deque *b_deque, t_deque_s *s_deque);
void	pb(t_deque *a_deque, t_deque *b_deque, t_deque_s *s_deque);
void	ra(t_deque *a_deque, t_deque_s *s_deque);
void	rb(t_deque *b_deque, t_deque_s *s_deque);
void	rr(t_deque *a_deque, t_deque *b_deque, t_deque_s *s_deque);
void	rra(t_deque *a_deque, t_deque_s *s_deque);
void	rrb(t_deque *b_deque, t_deque_s *s_deque);
void	rrr(t_deque *a_deque, t_deque *b_deque, t_deque_s *s_deque);
int		treat_deque_size_three_five(t_deques *dq);
void	sort_two_elements(t_deque *deque, t_deque_s *s_deque);
void	sort_two_elements_reverse_order(t_deque *deque, t_deque_s *s_deque);
void	sort_three_elements(t_deque *a_deque, t_deque_s *s_deque);
void	sort_five_elements(t_deque *a_deque, t_deque *b_deque, t_deque_s \
		*s_deque);
void	init_sort_id_in_three_five(t_sort_id_three_five *sort_id);
void	find_min_max_idx_in_three_five(t_deque *a_deque, t_sort_id_three_five \
		*sort_id);
void	a_to_b(t_deques *dq, int range);
void	b_to_a(t_deques *dq, int range);
void	process_in_a_to_b(t_deques *dq, t_sort_id *sort_id, int range);
void	process_in_b_to_a(t_deques *dq, t_sort_id *sort_id, int range);
void	sort(t_deques *dq);
int		init_sort_id(t_sort_id *sort_id, int range);
int		find_ra_rb_min(int ra_cnt, int rb_cnt);
int		*find_pivots(t_deque *deque, t_sort_id *sort_id, int range);
void	free_allocated_sort_id(t_sort_id *sort_id);
void	retreat_idx(t_deque *a_deque, t_deque *b_deque);
void	quick_sort(int *arr, int start, int end);
int		check_validation(t_deques *dq);
int		check_escape_condition_a_to_b(t_deques *dq, int range);
int		check_escape_condition_b_to_a(t_deques *dq, int range);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
size_t	get_len(char const *s, char c);

#endif
