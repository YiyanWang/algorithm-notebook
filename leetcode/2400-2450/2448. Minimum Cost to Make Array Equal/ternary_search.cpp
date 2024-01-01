#include <vector>
using namespace std;

// https://leetcode.com/problems/minimum-cost-to-make-array-equal/

class Solution {
public:
    long long minCost(vector<int> &nums, vector<int> &cost) {
        int n = cost.size();

        int left = pow(10, 6), right = 1, mid;
        for (int &num : nums) {
            if (num < left) left = num;
            if (num > right) right = num;
        }

        long long cost0 = 0LL, cost1 = 0LL;
        while (left < right) {
            cost0 = 0LL, cost1 = 0LL;
            mid = (left + right) / 2;
            for (int i = 0; i < n; i++) {
                cost0 += (long)abs(mid - nums[i]) * cost[i];
                cost1 += (long)abs(mid + 1 - nums[i]) * cost[i];
            }
            if (cost0 == 0 || cost1 == 0) break;

            if (cost0 >= cost1) left = mid + 1;
            else right = mid;
        }

        return min(cost0, cost1);
    }
};