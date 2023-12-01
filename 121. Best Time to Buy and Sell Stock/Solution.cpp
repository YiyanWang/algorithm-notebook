#include <vector>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        int l = 0, r = 0;
        int i = r, j = r;
        int min = prices[l], max = prices[r];

        while (j < prices.size())
        {
            for (; j < prices.size(); j++)
            {
                if (prices[j] >= max)
                {
                    max = prices[j];
                    r = j;
                }
            }
            for (; i < r; i++)
            {
                if (prices[i] < min)
                {
                    min = prices[i];
                    l = i;
                }
            }
            if (max - min > profit)
            {
                profit = max - min;
            }

            max = 0;
            i = r + 1;
            j = r + 1;
        }

        return profit;
    }
};