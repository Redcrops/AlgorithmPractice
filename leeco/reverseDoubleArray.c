#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int **reverseDoubleArray(int **array, int row, int col)
{
    int **acceptArray = (int **)malloc(sizeof(int *) * col);
    for (int idx = 0; idx < col; idx++)
    {
        acceptArray[idx] = (int *)malloc(sizeof(int) * row);
        memset(acceptArray[idx], 0, sizeof(int) * row);
    }

    for (int idx = 0; idx < row; idx++)
    {
        for (int jdx = 0; jdx < col; jdx++)
        {
            acceptArray[jdx][idx] = array[idx][jdx];
        }
    }
    return acceptArray;
}

int main()
{
    int array[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int row = 3;
    int col = 4;
    int **tempArray = (int **)malloc(sizeof(int *) * row);
    for (int idx = 0; idx < row; idx++)
    {
        tempArray[idx] = (int *)malloc(sizeof(int) * col);
        memset(tempArray[idx], 0, sizeof(int) * col);
        memcpy(tempArray[idx], array[idx], sizeof(int) * col);
    }

    int **reversedArray = reverseDoubleArray(tempArray, row, col);
    for (int idx = 0; idx < col; idx++)
    {
        for (int jdx = 0; jdx < row; jdx++)
        {
            printf("reversedArray[%d][%d]=%d\t", idx, jdx, reversedArray[idx][jdx]);
            if (jdx == row - 1)
            {
                printf("\n");
            }
        }
    }
    for (int idx = 0; idx < row; idx++)
    {
        if (tempArray[idx])
        {
            free(tempArray[idx]);
            tempArray[idx] = NULL;
        }
    }
    if (tempArray)
    {
        free(tempArray);
        tempArray = NULL;
    }

    for (int idx = 0; idx < col; idx++)
    {
        if (reversedArray[idx])
        {
            free(reversedArray[idx]);
            reversedArray[idx] = NULL;
        }
    }
    if (reversedArray)
    {
        free(reversedArray);
        reversedArray = NULL;
    }

    return 0;
}