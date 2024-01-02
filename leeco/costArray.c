// 给你一个 非严格递增排列 的数组 nums ，请你 原地 删
// 除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相
// 对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
// 输入：nums = [1,1,2]
// 输出：2, nums = [1,2,_]
// 解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。
// 不需要考虑数组中超出新长度后面的元素。
#include <stdio.h>
#define BUFFER_SIZE 10
int inplaceArray(int *array, int arraySize)
{
    int left = 1;
    for (int right = 1; right < arraySize; right++)
    {
        if (array[right] > array[right - 1])
        {
            array[left] = array[right];
            left++;
        }
        }
    return left;
}
int main()
{
    int array[BUFFER_SIZE] = {1, 1, 1, 2, 2, 3, 4, 4, 5, 6};
    // memset(array, 0, sizeof(array));

    int newSize = inplaceArray(array, BUFFER_SIZE);
    for (int idx = 0; idx < newSize; idx++)
    {
        printf("array[%d]=%d\t", idx, array[idx]);
        printf("\n");
    }

    return 0;
}