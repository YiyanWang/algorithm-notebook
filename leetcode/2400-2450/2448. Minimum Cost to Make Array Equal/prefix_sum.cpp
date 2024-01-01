#include <vector>
using namespace std;

// https://leetcode.com/problems/minimum-cost-to-make-array-equal/

class Solution {
public:
    long long minCost(vector<int> &nums, vector<int> &cost) {
        int n = nums.size();
        vector<pair<int, int>> nums_cost(n);
        for (int i = 0; i < n; i++) {
            nums_cost[i] = { nums[i], cost[i] };
        }

        sort(nums_cost.begin(), nums_cost.end());

        long long cost_sum = nums_cost[0].second;
        long long left_price = 0;
        long long right_price = 0;
        for (int i = 1; i < n; i++) {
            right_price += (long long)(nums_cost[i].first - nums_cost[0].first) * nums_cost[i].second;
            cost_sum += nums_cost[i].second;
        }

        long long ans = right_price;
        long long prefix_cost_sum = nums_cost[0].second;
        for (int i = 1; i < n; i++) {
            int diff = nums_cost[i].first - nums_cost[i - 1].first;
            left_price += diff * prefix_cost_sum;
            right_price -= diff * (cost_sum - prefix_cost_sum);
            prefix_cost_sum += nums_cost[i].second;
            ans = min(ans, left_price + right_price);
        }

        return ans;
    }
};