#include <stdio.h>
int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}
int min(int num1, int num2)
{
    return (num1 < num2) ? num1 : num2;
}
int maxStockPro(int *stockPrice, int priceSize)
{
    int pvLow = 10;
    int profit = 0;

    for (int idx = 0; idx < priceSize; idx++)
    {
        pvLow = min(stockPrice[idx], pvLow);
        profit = max(profit, stockPrice[idx] - pvLow);
    }
    return profit;
}
int main()
{
    int stockPrice[] = {7, 1, 4, 2, 5, 6, 3};
    int maxProfit = maxStockPro(stockPrice, sizeof(stockPrice) / sizeof(stockPrice[0]));
    printf("maxProfit=%d\n", maxProfit);
    return 0;
}