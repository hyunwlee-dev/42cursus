/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:13:31 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/12 19:38:53 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>

int		main(void)
{
	t_deque deque;

	printf("hello world!");
	if (is_empty(&deque))
		printf("hello world!");
	return (0);
}
