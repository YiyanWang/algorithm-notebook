#include <vector>
using namespace std;

// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        int end = 0;
        int reachable = 0;

        for (int i = 0; i < n - 1; i++) {
            reachable = max(reachable, nums[i] + i);

            if (i == end) {
                step++;
                end = reachable;
            }
        }

        return step;
    }
};