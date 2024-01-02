#include <stdio.h>
#define BUFFER_SIZE 7
int swap(int *num1, int *num2)
{
    int ret = 0;
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    return ret;
}
/*选择排序：相较于冒泡排序，减少了交换的次数*/
void selectSort(int *array, int numSize)
{
    if (array == NULL)
    {
        return;
    }
    for (int left = 0; left < numSize - 1; left++)
    {
        /*将left位置数作为min*/
        int min = left;

        for (int right = left + 1; right < numSize; right++)
        {
            if (array[right] < array[min])
            {
                min = right;
            }
        }
        swap(&array[left], &array[min]);
    }
}
void selectSort_01(int *array, int numSize)
{
    int minIndex = 0;
    for (int pos = 0; pos < numSize; pos++)
    {
        int minValue = array[pos];
        for (int begin = pos + 1; begin < numSize; begin++)
        {
            if (minValue > array[begin])
            {
                minValue = array[begin];
                minIndex = begin;
            }
        }
        if (array[pos] > minValue)
        {
            swap(&array[pos], &minValue);
        }
    }
}
int main()
{
    // int array[BUFFER_SIZE] = {5, 4, 3, 2, 1};
    int array[BUFFER_SIZE] = {1, 30, 24, 58, 12, 39, 5};
    selectSort(array, BUFFER_SIZE);
    for (int left = 0; left < BUFFER_SIZE; left++)
    {
        printf("%d\t", array[left]);
    }
    printf("\n");
    return 0;
}