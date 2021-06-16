/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:13:31 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/16 18:48:45 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	// t_deque b_deque;
	t_deque a_deque;

	a_deque.head = NULL;
	a_deque.tail = NULL;
	a_deque.size = 0;
	if (argc < 2)
	{
		puts("INPUT ERROR");
		exit(1);
	}
	for (int i = 1; i < argc; i++)
		add_rear(&a_deque, ft_atoi(argv[i]));

	printf("head_value: %d\n", a_deque.head->value);
	printf("tail_value: %d\n", a_deque.tail->value);
	printf("size : %d\n", a_deque.size);

    // for (;a_deque.size != 0;)
    // {
    //     printf("%d\n", a_deque.size);
	//     printf("[a_deque] delete_rear: %d\n\n", delete_rear(&a_deque));
    // }
    // printf("%d\n", a_deque.head->r_link->value);
    // printf("%d\n", a_deque.head->r_link->r_link->value);
    // printf("%d\n", a_deque.head->r_link->r_link->r_link->value);
    // printf("%d\n", a_deque.head->r_link->r_link->r_link->r_link->value);
    // printf("%d\n", a_deque.head->r_link->r_link->r_link->r_link->r_link->value);
    // printf("%d\n", a_deque.head->r_link->r_link->r_link->r_link->r_link->r_link->value);
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
	return (0);
}
