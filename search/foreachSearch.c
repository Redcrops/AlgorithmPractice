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

int findAppointValPos(int *array, int numSize, int val, int *pos)
{
    if (array == NULL)
    {
        return -1;
    }
    int flag = 0;
    for (int idx = 0; idx < numSize; idx++)
    {
        if (val == array[idx])
        {
            *pos = idx;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        *pos = -1;
    }
    /*没找到*/
    return -1;
}
int main()
{
    // srand(time(NULL));
    int array[BUFFER_SIZE] = {0};
    int pos = 0;
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        array[idx] = rand() % 100 + 1;
    }
    printArray(array, BUFFER_SIZE);
    findAppointValPos(array, BUFFER_SIZE, 16, &pos);
    printf("pos=%d\n", pos);

    return 0;
}