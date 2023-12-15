#include <set>
#include <vector>
using namespace std;

// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());

        int length = 0;
        int ans = 0;
        int last;
        for (auto it = numSet.begin(); it != numSet.end(); it++) {
            if (length == 0 || *it == last + 1) {
                length++;
                ans = max(ans, length);
            } else {
                length = 1;
            }
            last = *it;
        };

        return ans;
    }
};