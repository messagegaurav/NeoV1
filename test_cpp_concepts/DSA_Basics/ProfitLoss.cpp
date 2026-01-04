#include <bits/stdc++.h>
using namespace std;

int profitLoss(vector<int> prices)
{
    // finding the minimum price in the list
    // finding the max profit that day
    // return the profit
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); ++i)
    {
        int price = prices[i];
        printf("[DEBUG] Day %d: price = %d\n", i, price);
        int oldMin = minPrice;
        minPrice = min(minPrice, price);
        if (minPrice != oldMin)
        {
            printf("[DEBUG] New minPrice: %d\n", minPrice);
        }
        int profitToday = price - minPrice;
        printf("[DEBUG] Profit if sold today: %d\n", profitToday);
        int oldMax = maxProfit;
        maxProfit = max(maxProfit, profitToday);
        if (maxProfit != oldMax)
        {
            printf("[DEBUG] New maxProfit: %d\n", maxProfit);
        }
    }
    printf("[DEBUG] Final maxProfit: %d\n", maxProfit);
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    printf("[DEBUG] Input prices: ");
    for (int p : prices)
        printf("%d ", p);
    printf("\n");
    int result = profitLoss(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}