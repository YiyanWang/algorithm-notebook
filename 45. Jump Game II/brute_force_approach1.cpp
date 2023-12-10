#include <vector>
using namespace std;

// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        for (int i = 0, j = n - 1; i != j; i++) {
            if (nums[i] + i >= j) {
                step++;
                j = i;
                i = -1;
            }
        }
        return step;
    }
};