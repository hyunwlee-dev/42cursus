/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:20:46 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/07/30 18:50:58 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * def A_to_B(범위의 크기r)
 * 	스택A의 r개의 원소 중에서 "적절한" 피봇을 선택한다
 * 	for r개의 원소에 대해서
 *		if (스택A의 top) > 피봇
 *			ra명령으로 뒤로 넘긴다
 *			ra_호출_횟수++
 *		else
 *			pb명령으로 b로 보낸다
 *			pb_호출_횟수++
 *	for ra_호출 횟수
 *		rra #ra로 넘어간 원소들을 다시 스택 상단으로 되감기
 */
void    a_to_b(t_deque *a_deque, t_deque *b_deque, int start, int end)
{
    t_node  *node;
    int     pivot;
    
    ////////////////////////////////////////////////
    // 1️⃣ 피봇을 찾기 위한 것
    node = a_deque->head;
    pivot = 0;
    while (node->idx != (start + end) / 2)
        node = node->r_link;
    pivot = node->value;
    ft_putnbr(node->idx);
    ////////////////////////////////////////////////
    int ra_cnt = 0;
    int pb_cnt = 0;
    // 2️⃣ for r개의 원소에 대해서
    int i = start;
    while (i <= end)
    {
        if (a_deque->head->value > pivot)
        {
            ra(a_deque);
            ra_cnt++;
        }
        else
        {
            pb(a_deque, b_deque);
            pb_cnt++;
        }
        i++;
    }
    while (ra_cnt-- > 0)
        rra(a_deque);
    retreat_idx(a_deque, b_deque);
    // 2️⃣ - 1️⃣ if   (스택A의 top) > pivot
    // 2️⃣ - 2️⃣ else (스택A의 top) < pivot
    // 스택A의 r개의 원소 중에서 "적절한" 피봇을 선택한다.
    // while (a_deque->)
    // {
    //     pb_cnt++;
    // }
}

void    b_to_a(t_deque *a_deque, t_deque *b_deque, int start, int end)
{
    t_node  *node;
    int     pivot;
    
    node = b_deque->head;
    pivot = 0;
    while (node->idx != (start + end) / 2)
        node = node->r_link;
    pivot = node->value;
    ft_putnbr(node->idx);
    ////////////////////////////////////////////////
    int rb_cnt = 0;
    int pa_cnt = 0;
    // 2️⃣ for r개의 원소에 대해서
    int i = start;
    while (i <= end)
    {
        if (b_deque->head->value > pivot)
        {
            pa(a_deque, b_deque);
            pa_cnt++;
        }
        else
        {
            rb(b_deque);
            rb_cnt++;
        }
        i++;
    }
    while (rb_cnt-- > 0)
        rrb(b_deque);
    retreat_idx(a_deque, b_deque);
    // 2️⃣ - 1️⃣ if   (스택A의 top) > pivot
    // 2️⃣ - 2️⃣ else (스택A의 top) < pivot
    // 스택A의 r개의 원소 중에서 "적절한" 피봇을 선택한다.
    // while (a_deque->)
    // {
    //     pb_cnt++;
    // }
}

// void 	quick_sort(t_deque *a_deque, t_deque *b_deque, int start, int end)
// {
    // int left;
    // int right;
    // int pivot;

    // left = start;
    // right = end;
    // pivot = arr[(left + right) / 2];
    // // puts("---------------------------------");
	// // puts("---------------------------------");
	// // for(int i = 0; i < number; i++) // 출력
	// 	// printf("%d ", arr[i]);
	// // printf("\n\nleft: %d\n", left);
	// // printf("right: %d\n", right);
    // // printf("pivot value: %d\n\n", pivot);
    // while(left <= right)
    // {
    //     while(arr[left] < pivot)
    //         left++;
    //     while(arr[right] > pivot)
    //         right--;
    //     if(left <= right)
    //     {
    //         int temp = arr[left];
    //         arr[left] = arr[right];
    //         arr[right] = temp;
    //         left++;
    //         right--;
    //     }
    //     // printf("left: %d\n", left);
	//     // printf("right: %d\n", right);
    //     // printf("pivot value: %d\n", pivot);
    // }
	// // puts("=================================");
	// // puts("=================================\n\n");
    // // for(int i = 0; i < number; i++) // 출력
	// // 	printf("%d ", arr[i]);
    // puts("");
    // if (start < right)
    //     sort(arr, start, right);
    // if (left < end)
    //     sort(arr, left, end);
// }

// int     main()
// {
//     sort(arr, 0, number - 1);
//     for (int i = 0; i < number; i++)
//         printf("%d ", arr[i]);
// }
