#include <stdio.h>
#define BUFFER_SIZE 6
int main()
{
    int array[BUFFER_SIZE] = {2, 3, 1, 7, 5, 2};
    int val = 2;
    int left = 0;
    for (int right = 0; right < BUFFER_SIZE; right++)
    {
        if (array[right] != val)
        {
            array[left] = array[right];
            left++;
        }
    }
    for (int idx = 0; idx < left; idx++)
    {
        printf("array[%d]=%d\n", idx, array[idx]);
    }
    return 0;
}