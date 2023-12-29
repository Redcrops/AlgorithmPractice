#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NUM_SIZE 5
#define RAND_RANGE 20
#if 0 // 冒泡排序
void sort(int array[NUM_SIZE])
{
    int temp;
    for (int idx = 0; idx < NUM_SIZE - 1; idx++)
    {
        for (int jdx = 1; jdx < NUM_SIZE - idx; jdx++)
        {
            if (array[jdx] < array[jdx - 1])
            {
                temp = array[jdx];
                array[jdx] = array[jdx - 1];
                array[jdx - 1] = temp;
            }
        }
    }
}
#endif
#if 1
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
#endif
int main()
{
    int array[NUM_SIZE];
    memset(array, 0, sizeof(array));
    srand(time(NULL));
    for (int idx = 0; idx < NUM_SIZE; idx++)
    {
        array[idx] = rand() % RAND_RANGE + 1;
        printf("array[%d]=%d\n", idx, array[idx]);
    }
    bubbleSort(array,NUM_SIZE);
    printf("after sort array:\n");
    for (int jdx = 0; jdx < NUM_SIZE; jdx++)
    {

        printf("array[%d]=%d\n", jdx, array[jdx]);
    }
}
