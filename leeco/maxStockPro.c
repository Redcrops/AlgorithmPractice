#include <stdio.h>
#if 0
// int max(int num1, int num2)
// {
//     return (num1 > num2) ? num1 : num2;
// }
// int min(int num1, int num2)
// {
//     return (num1 < num2) ? num1 : num2;
// }
// int maxStockPro(int *stockPrice, int priceSize)
// {
//     int pvLow = 10;
//     int profit = 0;

//     for (int idx = 0; idx < priceSize; idx++)
//     {
//         pvLow = min(stockPrice[idx], pvLow);
//         profit = max(profit, stockPrice[idx] - pvLow);
//     }
//     return profit;
// }
#endif
int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}
int min(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}
int maxProfit(int *stockPrice, int day)
{
    int lowPrice = 10;
    int profit = 0;
    for (int idx = 0; idx < day; idx++)
    {
        lowPrice = min(lowPrice, stockPrice[idx]);
        profit = max(profit, stockPrice[idx] - lowPrice);
    }
    return profit;
}

int main()
{
    int stockPrice[] = {7, 1, 4, 2, 5, 6, 3};
    int maxStockProfit = maxProfit(stockPrice, sizeof(stockPrice) / sizeof(stockPrice[0]));
    printf("maxProfit=%d\n", maxStockProfit);
    return 0;
}