/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:13:31 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/18 17:15:07 by hyunwlee         ###   ########.fr       */
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
    quick_sort(&a_deque, &b_deque, 0, a_deque.size);
    clear(&a_deque, &b_deque);
	return (0);
}
