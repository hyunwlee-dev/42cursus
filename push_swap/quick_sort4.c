#include <stdio.h>
# define number 6

int arr[number] = {2, 1, 3, 6, 5, 8};

void    sort(int *arr, int start, int end)
{
    int left;
    int right;
    int pivot;

    left = start;
    right = end;
    pivot = arr[(left + right) / 2];
    puts("---------------------------------");
	puts("---------------------------------");
	for(int i = 0; i < number; i++) // 출력
		printf("%d ", arr[i]);
	printf("\n\nleft: %d\n", left);
	printf("right: %d\n", right);
    printf("pivot value: %d\n\n", pivot);
    while(left <= right)
    {
        while(arr[left] < pivot)
            left++;
        while(arr[right] > pivot)
            right--;
        if(left <= right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        printf("left: %d\n", left);
	    printf("right: %d\n", right);
        printf("pivot value: %d\n", pivot);
    }
	puts("=================================");
	puts("=================================\n\n");
    if (start < right)
        sort(arr, start, right);
    if (left < end)
        sort(arr, left, end);
}

int     main()
{
    sort(arr, 0, number - 1);
    for (int i = 0; i < number; i++)
        printf("%d ", arr[i]);
}
