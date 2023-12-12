#include <vector>
using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = INT_MAX;
        int sum = 0;

        while (r < n) {
            sum += nums[r];
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                if (ans == 1) {
                    return ans;
                }

                sum -= nums[l];
                l++;
            }
            r++;
        }

        return ans != INT_MAX ? ans : 0;
    }
};