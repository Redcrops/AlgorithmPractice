#include <stdio.h>
#define BUFFER_SIZE 7
#if 0
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
#endif
void insertSort_01(int *array, int numSize)
{
    if (array == NULL)
    {
        return;
    }
    int copy = 0;
    int left = 0;
    for (int right = 1; right < numSize; right++)
    {
        copy = array[right];
        left = right - 1;
        while (array[left] > copy && left >= 0)
        {
            array[left + 1] = array[left];
            left--;
        }
        array[left + 1] = copy;
    }
}
int printArray(int *array, int arraySize)
{
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("%d\t", array[idx]);
    }
    printf("\n");
}

int main()
{
    int array[BUFFER_SIZE] = {1, 30, 24, 5, 58, 12, 39};
    insertSort_01(array, BUFFER_SIZE);
    printArray(array, BUFFER_SIZE);
    return 0;
}