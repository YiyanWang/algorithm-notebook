#include <vector>
using namespace std;

// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int answer = nums[0], prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            if (prefixSum > answer) {
                answer = prefixSum;
            }
            if (prefixSum < 0) {
                prefixSum = 0;
            }
        }
        return answer;
    }
};