#include <stdio.h>
#define BUFFER_SIZE 6
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
int main()
{
    int array[6] = {45, 80, 55, 55, 42, 85};
    quikSort(array, 0, 5);
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("array[%d]=%d\t", idx, array[idx]);
    }
    printf("\n");
    return 0;
}