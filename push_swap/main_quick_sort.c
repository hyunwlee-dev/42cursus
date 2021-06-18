#include "push_swap.h"

void quick_sort(t_deque *a_deque, t_deque *b_deque, int start, int end)
{
    int pivot;
    int i;
    int j;
    int temp;

    pivot = a_deque->value;
    i = start + 1;
    j = end;
    if (start >= end)
        return ;

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}
