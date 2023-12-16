#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 32

int judgeReverseStr(char *str)
{
    char *temp = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    char *acceptTemp = temp;
    if (!temp)
    {
        return -1;
    }
    memset(temp, 0, sizeof(char) * BUFFER_SIZE);
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *temp = *str - 32;
            str++;
            temp++;
        }
        else if (*str >= 'A' && *str <= 'Z')
        {
            *temp = *str;
            str++;
            temp++;
        }
    }
    // *temp = '\0';用了memset可不加结束符
    // while (*temp != '\0')
    // {
    //     if (*temp >= 'a' && *temp <= 'z')
    //     {
    //         *temp = *temp - 32;
    //     }
    //     temp++;

    int len = strlen(acceptTemp);
    char *rvTemp = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (!rvTemp)
    {
        return -2;
    }
    memset(rvTemp, 0, sizeof(char) * BUFFER_SIZE);
    for (int idx = 0; idx < len; idx++)
    {
        rvTemp[idx] = acceptTemp[len - idx - 1];
    }
    int ret = strcmp(rvTemp, acceptTemp);
    if (temp)
    {
        free(acceptTemp); // 有问题
        temp = NULL;
    }
    if (rvTemp)
    {
        free(rvTemp); // 有问题
        rvTemp = NULL;
    }

    return ret;
}
int main(int argc, int *argv[])
{
    char *reverseStr = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (!reverseStr)
    {
        return -1;
    }
    memset(reverseStr, 0, sizeof(char) * BUFFER_SIZE);
    printf("input your string: ");
    scanf("%s", reverseStr);
    int result = judgeReverseStr(reverseStr);
    if (result != 0)
    {
        printf("String inputed is not reverse string\n");
    }
    printf("result=%d\n", result);
    if (reverseStr)
    {
        free(reverseStr);
        reverseStr = NULL;
    }
    return 0;
}