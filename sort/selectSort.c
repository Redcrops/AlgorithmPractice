#include <stdio.h>
#define BUFFER_SIZE 7
void selectSort(int *array, int numSize)
{
    int min = 0;
    int right = 0;
    for (int left = 0; left < numSize - 1; left++)
    {
        min = left;

        for (right = left + 1; right < numSize; right++)
        {
            if (array[right] < array[min])
            {
                min = right;
            }
        }

        int temp = array[left];
        array[left] = array[min];
        array[min] = temp;
    }
}
int main()
{
    // int array[BUFFER_SIZE] = {5, 4, 3, 2, 1};
    int array[BUFFER_SIZE] = {1, 30, 24, 5, 58, 12, 39};
    selectSort(array, BUFFER_SIZE);
    for (int left = 0; left < BUFFER_SIZE; left++)
    {
        printf("%d\t", array[left]);
    }
    printf("\n");
    return 0;
}