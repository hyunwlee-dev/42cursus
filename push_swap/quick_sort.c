#include<stdio.h>

int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int *data, int start, int end)
{
    int pivot = start;     // 피봇은 첫번째 원소
    int i = start + 1;
    int j = end;
    int temp;

    if (start >= end)      // 원소가 1개인 경우
        return;
    while (i <= j) {         // 엇갈릴 떄까지 반복
        while (data[i] <= data[pivot]) { // 피봇값 보다 큰 값을 만날 때까지 오른쪽으로 이동
            i++;
        }
        while (data[j] >= data[pivot] && j > start) { // 피봇값 보다 작은 값을 만날 때까지 왼쪽으로 이동 , j는 start보다 큼
            j--;
        }
        if (i > j) {    // 현재 엇갈린 상태면 피봇값과 교체
            temp = data[pivot];
            data[pivot] = data[j];
            data[j] = temp;
        } else {    // 엇갈리지 않았다면 i와 j를 교체
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    // 재귀적 함수를 이용
    quickSort(data, start, j-1);
    quickSort(data, j+1, end);
}

int main(int argc, char **argv)
{
    quickSort(data,0, number-1);
    int i;
    for(i = 0; i < number; i++)
        printf("%d ",data[i]);
    return 0;
}
