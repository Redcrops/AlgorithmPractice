#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NUM_SIZE 5
#define RAND_RANGE 20
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
    sort(array);
    printf("after sort array:\n");
    for (int jdx = 0; jdx < NUM_SIZE; jdx++)
    {

        printf("array[%d]=%d\n", jdx, array[jdx]);
    }
}