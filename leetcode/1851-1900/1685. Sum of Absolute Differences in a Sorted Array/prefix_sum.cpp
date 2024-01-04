#include <vector>
using namespace std;

// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
        int n = nums.size(), prefix = 0, suffix = 0;
        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            answer[i] += (i + 1) * nums[i] - prefix;

            int j = n - 1 - i;
            answer[j] += suffix - (n - 1 - j) * nums[j];
            suffix += nums[j];
        }
        return answer;
    }
};