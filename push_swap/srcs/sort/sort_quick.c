/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:12:23 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 18:59:28 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *arr, int start, int end)
{
	t_quick_sort	qs;

	qs.left = start;
	qs.right = end;
	qs.pivot = arr[(qs.left + qs.right) / 2];
	while (qs.left <= qs.right)
	{
		while (arr[qs.left] < qs.pivot)
			qs.left++;
		while (arr[qs.right] > qs.pivot)
			qs.right--;
		if (qs.left <= qs.right)
		{
			qs.temp = arr[qs.left];
			arr[qs.left] = arr[qs.right];
			arr[qs.right] = qs.temp;
			qs.left++;
			qs.right--;
		}
	}
	if (start < qs.right)
		quick_sort(arr, start, qs.right);
	if (qs.left < end)
		quick_sort(arr, qs.left, end);
}
