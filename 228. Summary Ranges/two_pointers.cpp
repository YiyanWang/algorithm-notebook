#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();

        vector<string> ans;
        for (int a = 0, b = 1; b <= n; b++) {
            if (b == n || nums[b] != nums[b - 1] + 1) {
                if (b == a + 1) {
                    ans.push_back(to_string(nums[a]));
                } else {
                    ans.push_back(to_string(nums[a]) + "->" + to_string(nums[b - 1]));
                }
                a = b;
            }
        }

        return ans;
    }
};