#include <stdio.h>

#define BUFFER_SIZE 5

int swap(int *num1, int *num2)
{
    int ret = 0;
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    return ret;
}

int printArray(int *array, int arraySize)
{
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("%d\t", array[idx]);
    }
    printf("\n");
}

/*时间复杂度：o(n²)*/
void bubbleSort01(int *array, int arraySize)
{
    for (int end = arraySize; end > 0; end--)
    {
        for (int begin = 1; begin < arraySize; begin++)
        {
            /*后面数比前面小就交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&array[begin], &array[begin - 1]);
            }
        }
    }
}
/*自己写的*/
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
/*优化1*/
void bubbleSort02(int *array, int arraySize)
{
    int sorted = 1;
    for (int end = arraySize; end > 0; end--)
    {
        sorted = 1;
        for (int begin = 1; begin < arraySize; begin++)
        {
            /*后面数比前面小就交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&array[begin], &array[begin - 1]);
                int sorted = 0;
            }
        }

        printf("sorted=%d\n", sorted);
        if (sorted == 1)
        {
            break;
        }
    }
}
/*优化2*/
void bubbleSort03(int *array, int arraySize)
{

    int sortedIndex = 0;
    for (int end = arraySize; end > 0; end--)
    {

        sortedIndex = 1;
        for (int begin = 1; begin < arraySize; begin++)
        {
            /*后面数比前面小就交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&array[begin], &array[begin - 1]);

                sortedIndex = begin;
            }
        }
        end = sortedIndex;
    }
}
int main()
{
    int array[BUFFER_SIZE] = {5, 4, 3, 2, 1};
    int len = sizeof(array) / sizeof(array[0]);

    bubbleSort02(array, len);
    printArray(array, len);
    return 0;
}