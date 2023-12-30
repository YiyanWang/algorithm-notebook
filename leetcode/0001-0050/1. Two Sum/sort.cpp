#include <vector>
using namespace std;

// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = { nums[i], i };
        }

        sort(pairs.begin(), pairs.end());
        for (int i = 0, j = n - 1; i < j;) {
            int sum = pairs[i].first + pairs[j].first;
            if (sum > target) j--;
            else if (sum < target) i++;
            else return { pairs[i].second ,pairs[j].second };
        }

        return { -1, -1 };
    }
};