#include <stdio.h>
#define BUFFER_SIZE 6
int deleSameVal(int *array, int arraySize, int val)
{
    int left = 0;
    for (int right = 0; right < BUFFER_SIZE; right++)
    {
        if (val != array[right])
        {
            array[left] = array[right];
            left++;
        }
        }
    return left;
}
int main()
{
    int array[BUFFER_SIZE] = {2, 3, 1, 7, 5, 2};
    int val = 2;
    int size = deleSameVal(array, BUFFER_SIZE, val);
    for (int idx = 0; idx < size; idx++)
    {
        printf("array[%d]=%d\n", idx, array[idx]);
    }
    return 0;
}

#if 0
  for (int right = 0; right < BUFFER_SIZE; right++)
    {
        if (array[right] != val)
        {
            array[left] = array[right];
            left++;
        }
    }
#endif