#include <stdio.h>
//퀵정렬
int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int *data, int start, int end)
{
	int i = start;
	int j = end;
	int pivot = data[(i + j) / 2];
	printf("pivot: %d\n", pivot);
	int temp;

	if(start >= end)
		return;
	while(i <= j)
	{
		while(data[i] < data[pivot])
			i++;
		while(data[j] > data[pivot])
			j--;
		if(i <= j)					// i와 j가 엇갈리지 않았을 때
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i++;
			j--;
		}
	}
	quickSort(data, start, j);
	quickSort(data, i, end);
}

int main()
{
	quickSort(data, 0, number - 1);

	for(int i = 0; i < number; i++) // 출력
		printf("%d ", data[i]);
}
