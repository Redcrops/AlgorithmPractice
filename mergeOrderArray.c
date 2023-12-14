#include <stdio.h>
#include <stdlib.h>

int *mergeOrderNums(int *nums1, int nums1Size, int *nums2, int nums2Size, int *newNumSize)
{

    int *sorted = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    if (!sorted)
    {
        return NULL;
    }
    int idx = 0;
    int jdx = 0;
    int kdx = 0;
    while (idx < nums1Size && jdx < nums2Size)
    {
        if (nums1[idx] < nums2[jdx])
        {
            sorted[kdx++] = nums1[idx++];
        }
        else
        {
            sorted[kdx++] = nums2[jdx++];
        }
    }
    while (jdx < nums2Size)
    {
        sorted[kdx++] = nums2[jdx++];
    }
    while (idx < nums1Size)
    {
        sorted[kdx++] = nums1[idx++];
    }

    *newNumSize = nums1Size + nums2Size;
    return sorted;
}
int main()
{
    int array1[5] = {1, 2, 2, 3, 4};
    int array2[3] = {2, 5, 6};
    int ret;
    int *sorted = mergeOrderNums(array1, 5, array2, 3, &ret);

    for (int idx = 0; idx < ret; idx++)
    {
        printf("%d\t", sorted[idx]);
    }
    if (sorted != NULL)
    {
        free(sorted);
        sorted = NULL;
    }
    printf("\n");
    return 0;
}