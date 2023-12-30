#include <vector>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            int left = target - nums[i];
            auto it = index.find(left);
            if (it != index.end()) {
                return { i, it->second };
            }
            index[nums[i]] = i;
        }

        return { -1, -1 };
    }
};