#include <vector>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        int profit;

        for (int i = 1; i < prices.size(); i++) {
            profit = prices[i] - prices[i - 1];
            if (profit > 0) {
                totalProfit += profit;
            }
        }

        return totalProfit;
    }
};