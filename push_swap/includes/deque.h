/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:11:09 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 23:19:19 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include "push_swap.h"
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				idx;
	int				value;
	struct s_node	*l_link;
	struct s_node	*r_link;
}	t_node;

typedef struct s_deque
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}	t_deque;

typedef struct s_node_s
{
	int				idx;
	char			*s;
	struct s_node_s	*l_link;
	struct s_node_s	*r_link;
}	t_node_s;

typedef struct s_deque_s
{
	struct s_node_s	*head;
	struct s_node_s	*tail;
	int				size;
}	t_deque_s;

typedef struct s_deques
{
	struct s_deque		a_deque;
	struct s_deque		b_deque;
	struct s_deque_s	s_deque;
}	t_deques;

t_node		*creat_node(t_node *l_link, t_node *r_link, int value, int idx);
int			add_front(t_deque *deque, int value);
int			add_rear(t_deque *deque, int value);
int			delete_front(t_deque *deque);
int			delete_rear(t_deque *deque);
int			get_front(t_deque *deque);
int			get_rear(t_deque *deque);
void		clear(t_deques *dq);
void		clear_s(t_deque_s *deque);
void		print_all(t_deque *deque);
t_node_s	*creat_node_s(t_node_s *l_link, t_node_s *r_link, char *s, int idx);
void		add_rear_s(t_deque_s *deque, char *s);
char		*delete_rear_s(t_deque_s *deque);
char		*get_front_s(t_deque_s *deque);
void		print_all_s(t_deque_s *deque);
int			init_total(t_deques *dq, int argc, char **argv);
int			init_deques(t_deque *a_deque, t_deque *b_deque, int argc, \
		char **argv);
void		init_deques_s(t_deque_s *s_deque);
int			fill_deque_envp(t_deque *a_deque, char **argv);
int			fill_deque_general(t_deque *a_deque, int argc, char **argv);
int			check_integer(char **input, int input_len, int start_idx);
int			check_integer_range(char **input, int input_len, int start_idx);
int			check_integer_range_compare(char **input, int idx, int is_minus);
int			check_duplication_or_sorted(t_deque *a_deque);
int			check_optimization_case(char *first, char *second);
int			rotate_list(t_deque *a_deque, int node_i_value, int cnt, \
		int *is_sorted);
char		*find_left_list_s(t_deque_s *s_deque);
void		free_splited(char **arr, int len);
void		optimize_deque(t_deque_s *s_deque, char *s);
int			treat_deque_size_zero_one_in_delete(t_deque *deque);
char		*treat_deque_size_zero_one_in_delete_s(t_deque_s *deque);

#endif
