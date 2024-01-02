#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define NUM_SIZE 5
#define RANGE_NUM 20
#define RET_SIZE 2
void sum_Num(int array[NUM_SIZE], int target, int ret[RET_SIZE])
{

    int sum_Num = 0;
    for (int idx = 0; idx < NUM_SIZE - 1; idx++)
    {
        for (int jdx = 1; jdx < NUM_SIZE - idx; jdx++)
        {
            if (array[idx] + array[jdx] == target)
            {
                ret[0] = idx;
                ret[1] = jdx;
                return;
            }
        }
    }
    ret[0] = -1;
    ret[1] = -1;
}
int main()
{
    int array[NUM_SIZE];
    // memset(array, 0, sizeof(array));
    int target;
    int ret[RET_SIZE];
    memset(array, 0, sizeof(ret));
    srand(time(NULL));
    for (int idx = 0; idx < NUM_SIZE; idx++)
    {
        array[idx] = rand() % RANGE_NUM + 1;
    }
    for (int jdx = 0; jdx < NUM_SIZE; jdx++)
    {
        printf("array[%d]=%d\n", jdx, array[jdx]);
    }
    printf("input your target num:\n");
    scanf("%d", &target);
    sum_Num(array, target, ret);
    if ((ret[0] == -1) && (ret[1] == -1))
    {
        printf("no result you want !\n");
    }
    else
    {
        printf("(%d,%d)\n", ret[0], ret[1]);
    }

    return 0;
}