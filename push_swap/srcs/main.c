/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:13:31 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/22 22:54:43 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_deque a_deque;
	t_deque b_deque;

    if (argc < 2)
	{
        ft_putstr("ERROR\n");
        return (0);
	}
    if (init_deques(&a_deque, &b_deque, argc, argv))
        return (0);
    print_all(&a_deque);
    print_all(&b_deque);
    // ft_putstr("-------------------------------------------------\n");
    // delete_front(&a_deque);
    // delete_front(&a_deque);
    // delete_front(&a_deque);
    ft_putstr("-------------------------------------------------\n");
    a_to_b(&a_deque, &b_deque, 0, a_deque.size - 1);
    ft_putstr("-------------------------------------------------\n");
    print_all(&a_deque);
    print_all(&b_deque);
    // delete_front(&a_deque);
    // ft_putstr("0idx: ");
    // ft_putnbr(a_deque.head->idx);
    // ft_putstr("\n");
    // ft_putstr("1idx: ");
    // ft_putnbr(a_deque.head->r_link->idx);
    // ft_putstr("\n");
    // ft_putstr("2idx: ");
    // ft_putnbr(a_deque.head->r_link->r_link->idx);
    // ft_putstr("\n");
    // ft_putstr("3idx: ");
    // ft_putnbr(a_deque.head->r_link->r_link->r_link->idx);
    // ft_putstr("\n");
    // ft_putstr("0idx: ");
    // ft_putnbr(a_deque.head->r_link->r_link->r_link->r_link->idx);
    // ft_putstr("\n");
    // quick_sort(&a_deque, &b_deque, 0, a_deque.size);
    // clear(&a_deque, &b_deque);
	return (0);
}
