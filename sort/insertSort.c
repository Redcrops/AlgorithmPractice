#include <stdio.h>
#define BUFFER_SIZE 7
void insertSort(int *array, int numSize)
{
    int copy = 0;
    int left = 0;
    for (int right = 1; right < BUFFER_SIZE; right++)
    {
        /*copy要比较的数*/
        copy = array[right];
        /*left为已有序数组中向左移动的下标*/
        left = right - 1;
        while (left >= 0 && array[left] > copy)
        {
            /*找到比copy大的数就后移，left向左移*/
            array[left + 1] = array[left];
            left--;
        }
        /*退出循环时，left位置为array[left]<=copy的位置，所以copy的位置在left后面*/
        array[left + 1] = copy;
    }
}

int main()
{
    int array[BUFFER_SIZE] = {1, 30, 24, 5, 58, 12, 39};
    insertSort(array, BUFFER_SIZE);
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("%d\t", array[idx]);
    }
    printf("\n");
    return 0;
}