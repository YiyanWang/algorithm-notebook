#include <vector>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int ans = 0;
        for (auto it = numSet.begin(); it != numSet.end(); it++) {
            if (!numSet.count(*it - 1)) {
                int length = 1;
                while (numSet.count(*it + length)) {
                    length++;
                }
                ans = max(ans, length);
            }
        };

        return ans;
    }
};