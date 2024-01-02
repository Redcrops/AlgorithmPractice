#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define BUFFER_SIZE 10
int printArray(int *array, int arraySize)
{
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("%d\t", array[idx]);
    }
    printf("\n");
}
/*二分查找适合已经排好的数据*/
int binarySearchIsExist(int *array, int begin, int end, int target)
{
    if (array == NULL)
    {
        return 0;
    }
    while (begin <= end)
    {
        int mid = (begin + (end - begin)) >> 1;
        if (target < array[mid])
        {
            end = mid - 1;
        }
        else if (target > array[mid])
        {
            begin = mid + 1;
        }
        else
        {
            return 1;
        }
    }
    return -1;
}

void bubbleSort(int *array, int arraySize)
{
    int temp = 0;
    for (int idx = 0; idx < arraySize - 1; idx++)
    {
        for (int jdx = 1; jdx < arraySize - idx; jdx++)
        {
            if (array[jdx - 1] > array[jdx])
            {
                temp = array[jdx - 1];
                array[jdx - 1] = array[jdx];
                array[jdx] = temp;
            }
        }
    }
}
int main()
{
    // srand(time(NULL));
    int array[BUFFER_SIZE] = {0};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        array[idx] = rand() % 100 + 1;
    }
    printArray(array, BUFFER_SIZE);
    bubbleSort(array, BUFFER_SIZE);
    printf("sorted\n");
    printArray(array, BUFFER_SIZE);
    int ret = binarySearchIsExist(array, 0, BUFFER_SIZE - 1, 16);
    printf("ret=%d\n", ret);
    return 0;
}