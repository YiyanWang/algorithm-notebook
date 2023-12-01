#include <vector>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int profit = 0;
        int min = prices[0];

        for (int price : prices)
        {
            if (price < min)
            {
                min = price;
            }
            else if ((profit = price - min) > maxProfit)
            {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};