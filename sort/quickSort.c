#include <stdio.h>
#define BUFFER_SIZE 6
#if 1
int getPivotPos(int *array, int low, int high)
{
    int pivot = array[low];
    while (low < high)
    {
        while (array[high] >= pivot && low < high)
        {
            high--;
        }
        array[low] = array[high];
        while (array[low] <= pivot && low < high)
        {
            low++;
        }
        array[high] = array[low];
    }

    array[low] = pivot;
    return low;
}
void quikSort(int *array, int low, int high)
{
    int pivotPos = 0;
    if (low < high)
    {
        pivotPos = getPivotPos(array, low, high);
        quikSort(array, low, pivotPos - 1);
        quikSort(array, pivotPos + 1, high);
    }
}
#endif
/*时间复杂度o(NlogN)*/
#if 0
int getPivotPos(int *array, int low, int high)
{
    int pivot = array[low];
    while (low < high)
    {
        while (array[high] >= pivot && low < high)
        {
            high--;
        }
        array[low] = array[high];
        // low++;
        while (array[low] <= pivot && low < high)
        {
            low++;
        }
        array[high] = array[low];
        // high--;
    }
    array[low] = pivot;
    return low;
}
#endif
#if 0
void quickSort_01(int *array, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pivotPos = 0;
    int pivot = array[low];
    while (low < high)
    {
        while (array[high] >= pivot && low < high)
        {
            high--;
        }
        array[low] = array[high];
        // low++;
        while (array[low] <= pivot && low < high)
        {
            low++;
        }
        array[high] = array[low];
        // high--;
    }
    array[low] = pivot;
    pivotPos = low;

    quickSort_01(array, low, pivotPos - 1);
    quickSort_01(array, pivotPos + 1, high);
}
#endif
void printArray(int *array, int arraySize)
{
    if (array == NULL)
    {
        return;
    }
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("%d\t", array[idx]);
    }
    printf("\n");
}
int main()
{
    int array[] = {59, 80, 55, 58, 42, 85};
    quickSort_01(array, 0, 5);
    // int pos = getPivotPos(array, 0, 5);
    printArray(array, 6);
    // printf("pos=%d\n", pos);
    return 0;
}