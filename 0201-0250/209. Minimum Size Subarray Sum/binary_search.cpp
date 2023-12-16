#include <vector>
using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min = 1, max = n;
        int ans = INT_MAX;

        while (min <= max) {
            int length = (max + min) / 2;

            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                if (i >= length) {
                    sum -= nums[i - length];
                }

                if (sum >= target) {
                    break;
                }
            }

            if (sum >= target) {
                max = length - 1;
                ans = length;
            } else {
                min = length + 1;
            }
        }

        if (ans != INT_MAX) {
            return ans;
        }
        return 0;
    }
};