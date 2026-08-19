#include <iostream>
#include <vector>
#include <climits>

// Basic approach using O(n^2) Brute force
void findMaxProfit(const std::vector<int> stocks)
{
    int left = 0, right = 0;
    int maxProfit = 0;

    int n = (int)stocks.size();

    while (left < n)
    {
        while (right < n)
        {
            if (maxProfit < (stocks[right] - stocks[left]) && (stocks[left] <= stocks[right]))
            {
                maxProfit = stocks[right] - stocks[left];
                std::cout << "Sell Date: " << left << " Sell Price: " << stocks[left] << "\n";
                std::cout << "Buy Date: " << right << " Buy Price: " << stocks[right] << "\n";
            }
            right++;
        }
        left++;
        right = left + 1;
    }
    std::cout << "\n \n Max Profit: " << maxProfit << "\n";
}

// start comparison...if smaller, move to minSell, and if bigger move to maxBuy
void smartWay(const std::vector<int> stocks)
{
    if (stocks.empty())
    {
        std::cout << "Empty inputs ..>!!!" << "\n";
        return;
    }
    int n = stocks.size();

    if (n > 1)
    {

        int minBuy = INT_MAX, maxProfit = 0;
        int buyIndex = 0, saleIndex = 1, minIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if ((stocks[i] < minBuy))
            {
                minBuy = stocks[i];
                minIndex = i;
            }

            int profit = stocks[i] - minBuy;
            if (profit > maxProfit)
            {
                maxProfit = profit;
                saleIndex = i;
                buyIndex = minIndex;
            }
        }
        if (maxProfit > 0)
        {
            std::cout << "Min Buy Price: " << stocks[buyIndex] << " on " << buyIndex << "\n";
            std::cout << "Max Sale Price: " << stocks[saleIndex] << " on " << saleIndex << "\n";
            std::cout << "Max Profit: " << maxProfit << "\n";
        }
        else
        {
            std::cout << "No profit deal.. exit..!!!" << "\n";
        }
    }
}

int main()
{
    std::vector<int> stocks = {5, 2, 7, 3, 10, 6, 4, -5};
    findMaxProfit(stocks);
    smartWay(stocks);
    std::cout << "\n";
    return 0;
}