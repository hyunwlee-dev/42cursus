/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:13:31 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/16 21:58:38 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_deque a_deque;
	t_deque b_deque;

    init_deques(&a_deque, &b_deque);
    if (argc < 2)
	{
        clear(&a_deque, &b_deque);
        ft_putstr("ERROR\n");
	}
	for (int i = 1; i < argc; i++)
		if (add_rear(&a_deque, ft_atoi(argv[i])))
        {
            clear(&a_deque, &b_deque);
            ft_putstr("ERROR\n");
        }

    ft_putstr("a_deque.head->value: ");
	ft_putnbr(a_deque.head->value);
    ft_putchar('\n');
    ft_putstr("a_deque.tail->value: ");
	ft_putnbr(a_deque.tail->value);
    ft_putstr("\n");
    ft_putstr("a_deque.size: ");
	ft_putnbr(a_deque.size);
    ft_putchar('\n');
    ft_putchar('\n');

	add_rear(&b_deque, 42);
    // clear(&a_deque, &b_deque);
    //🔥
    // // sa(&a_deque);
    // pa(&a_deque, &b_deque);
    // // pb(&a_deque, &b_deque);

    // for (;a_deque.size != 0;)
    // {
    //     ft_putstr("a_deque.size: ");
    //     ft_putnbr(a_deque.size);
    //     ft_putstr("\n");
    //     ft_putstr("a_deque.value: ");
	//     ft_putnbr(delete_front(&a_deque));
    //     ft_putstr("\n");
    // }
	// ft_putnbr(delete_front(&a_deque));
    // ft_putstr("\n");
    // for (;b_deque.size != 0;)
    // {
    //     ft_putstr("b_deque.size: ");
    //     ft_putnbr(b_deque.size);
    //     ft_putstr("\n");
    //     ft_putstr("b_deque.value: ");
	//     ft_putnbr(delete_front(&b_deque));
    //     ft_putstr("\n");
    //     ft_putstr("\n");
    // }    
    //🔥
   // start
   // 4
   // 3
   // 2
   // 4
   // 3
   // 2
   // end
    ra(&a_deque);
    rra(&a_deque);
    ft_putnbr(a_deque.head->value);
    ft_putstr("\n");
    ft_putnbr(a_deque.tail->value);
    ft_putstr("\n");
    ft_putstr("start\n");
    ft_putnbr(a_deque.head->l_link->value);
    ft_putstr("\n");
    ft_putnbr(a_deque.head->l_link->l_link->value);
    ft_putstr("\n");
    ft_putnbr(a_deque.head->l_link->l_link->l_link->value);
    ft_putstr("\n");
    ft_putnbr(a_deque.head->l_link->l_link->l_link->l_link->value);
    ft_putstr("\n");
    ft_putnbr(a_deque.head->l_link->l_link->l_link->l_link->l_link->value);
    ft_putstr("\n");
    ft_putnbr(a_deque.head->l_link->l_link->l_link->l_link->l_link->l_link->value);
    ft_putstr("\n");
    ft_putstr("end\n");
	// puts("");
    // printf("%d\n", a_deque.tail->r_link->value);
    // printf("%d\n", a_deque.tail->r_link->r_link->value);
    // printf("%d\n", a_deque.tail->r_link->r_link->r_link->value);
    // printf("%d\n", a_deque.tail->r_link->r_link->r_link->r_link->value);
    // printf("%d\n", a_deque.tail->r_link->r_link->r_link->r_link->r_link->value);
    // printf("%d\n", a_deque.tail->r_link->r_link->r_link->r_link->r_link->r_link->value);
	
    // printf("[a_deque] delete_front: %d\n", delete_front(&a_deque));
	/////////////////////////////////////////////////////////
	// add_rear(&b_deque, 3);
	// add_rear(&b_deque, 1);
	/////////////////////////////////////////////////////////
	// pa(&a_deque, &b_deque);

	// ra(&a_deque);
	// while (is_empty(&a_deque))
	// {
	// 	printf("[a_deque] delete_front: %d\n", delete_front(&a_deque));
	// }
	// pb(&a_deque, &b_deque);
	// printf("[b_deque] get_front: %d\n", get_front(&b_deque));
	// printf("[b_deque] get_rear: %d\n", get_rear(&b_deque));
	// printf("[a_deque] delete_front: %d\n", delete_front(&a_deque));
	// printf("[a_deque] delete_front: %d\n", delete_front(&a_deque));
	// printf("[a_deque] delete_front: %d\n", delete_front(&a_deque));
    // clear(&a_deque, &b_deque);
	return (0);
}
