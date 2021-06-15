/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:13:31 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/15 22:04:00 by hyunwlee         ###   ########.fr       */
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

	printf("%s\n", argv[1]);
	if (argc < 2)
	{
		puts("INPUT ERROR");
		exit(1);
	}
	for (int i = 1; i < argc; i++)
		add_rear(&a_deque, ft_atoi(argv[i]));

	/////////////////////////////////////////////////////////
	// add_rear(&b_deque, 3);
	// add_rear(&b_deque, 1);
	/////////////////////////////////////////////////////////
	// pa(&a_deque, &b_deque);

	ra(&a_deque);
	while (is_empty(&a_deque))
	{
		printf("[a_deque] delete_front: %d\n", delete_front(&a_deque));
	}
	// pb(&a_deque, &b_deque);
	printf("[a_deque] get_front: %d\n", get_front(&a_deque));
	printf("[a_deque] get_rear: %d\n", get_rear(&a_deque));
	// printf("[b_deque] get_front: %d\n", get_front(&b_deque));
	// printf("[b_deque] get_rear: %d\n", get_rear(&b_deque));
	// printf("[a_deque] delete_front: %d\n", delete_front(&a_deque));
	// printf("[a_deque] delete_front: %d\n", delete_front(&a_deque));
	// printf("[a_deque] delete_front: %d\n", delete_front(&a_deque));
	return (0);
}
