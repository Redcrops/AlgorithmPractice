#include <stdio.h>
#if 0
char *hex16(unsigned int num)
{
    unsigned int mask = 0xf; // 0000 0000 0000 0000 0000 0000 0000 1111作用是取低四位
    static char hex[11];     // 错误：char hex[11];hex是局部变量保存在栈上
    // 另外一种写法：char *hex=(char *)malloc(sizeof(char)11);申请空间
    // 用完之后free(hex);释放空间，堆空间
    // 或者用全局变量 char hex[11];
    int temp;
    hex[0] = '0';
    hex[1] = 'x';
    hex[11] = '\0';
    for (int i = 0; i < 8; i++)
    {
        temp = num & mask;
        if (temp < 10)
        {
            hex[9 - i] = temp + '0';
        }
        else
        {
            hex[9 - i] = temp - 10 + 'a';
        }
        num = num >> 4;
    }
    return hex;
}

int main()
{
    unsigned int num;
    printf("输入数字num：");
    scanf("%d", &num);
    char *hex = hex16(num); // 释放了hex所在的栈空间
    printf("转换后的数：%s\n", hex);
    return 0;
}
#endif

char *hex16(unsigned int num)
{
    static char hex[11];
    int temp;
    unsigned int mask = 0xf;
    hex[0] = '0';
    hex[1] = 'x';
    hex[11] = '\0';
    for (int i = 0; i < 8; i++)
    {
        temp = num & mask;
        if (temp >= 10)
        {
            hex[9 - i] = temp - 10 + 'a';
        }
        else
        {
            hex[9 - i] = temp + '0';
        }
        num = num >> 4;
    }
    return hex;
}
int main()
{
    unsigned int num;
    printf("请输入数字num=");
    scanf("%u", &num);
    char *hex = hex16(num);
    printf("转换后的数:%s\n", hex);
    return 0;
}
