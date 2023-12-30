#include <vector>
using namespace std;

// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = nums.size() - 1;
        int reach = max;
        for (int i = max; i >= 0; i--) {
            if (nums[i] == 0) {
                if (reach == max) {
                    reach = i;
                }
            } else if (reach != max && reach - i < nums[i]) {
                reach = max;
            }
        }

        return reach == max;
    }
};