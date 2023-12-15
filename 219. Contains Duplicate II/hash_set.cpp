#include <vector>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> set;

        for (int i = 0, j = 0; j < n; j++) {
            if (set.find(nums[j]) != set.end()) {
                return true;
            }

            set.insert(nums[j]);
            if (j - i == k) {
                set.erase(nums[i++]);
            }
        }

        return false;
    }
};