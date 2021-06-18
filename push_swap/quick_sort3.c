#include <stdio.h>
#define number 5

int data[number] = {1, 5, 3, 4, 2};

int partition(int *data, int left, int right, int pivotIdx)
{
	int temp;
	int pivot;

	puts("---------------------------------");
	for(int i = 0; i < number; i++) // 출력
		printf("%d ", data[i]);
	printf("\n\nleft: %d\n", left);
	printf("right: %d\n", right);
	printf("pivotIdx: %d\n", pivotIdx);
	pivot = data[pivotIdx];
	while(left <= right)
	{
		while(data[left] < pivot)
			left++;
		while(data[right] > pivot)
			right--;
		if(left <= right)
		{
			temp = data[left];
			data[left] = data[right];
			data[right] = temp;
			left++;
			right--;
		}
	}
	printf("left: %d\n", left);
	printf("right: %d\n", right);
	printf("pivotIdx: %d\n", pivotIdx);
	puts("---------------------------------");
	temp = data[left];
	data[left] = data[pivotIdx];
	data[pivotIdx] = temp;
	return (left);
}

void	 quickSort(int *data, int data_size, int left, int right)
{
	int pivotIdx;

	// if (!left)
	// 	left = 0;
	// if (!right)
	// 	right = data_size - 1;
	pivotIdx = right;
	pivotIdx = partition(data, left, right - 1, pivotIdx);
	if (left < pivotIdx - 1)
	{
		puts("1)");
		quickSort(data, data_size, left, pivotIdx - 1);
	}
	if (pivotIdx + 1 < right)
	{
		puts("2)");
		quickSort(data, data_size, pivotIdx + 1, right);
	}
}

int main()
{
	puts("Quick Sort START");
	quickSort(data, number, 0, number - 1);
	for(int i = 0; i < number; i++) // 출력
		printf("%d ", data[i]);
}
