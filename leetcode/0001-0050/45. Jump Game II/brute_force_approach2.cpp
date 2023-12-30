#include <vector>
using namespace std;

// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int reachable;
        nums[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            reachable = nums[i] + i;
            if (reachable > n - 1) {
                nums[i] = 1;
            } else if (nums[i] != 0) {
                nums[i] = nums[reachable] + 1;
            } else {
                nums[i] = nums[i + 1] + 1;
            }

            for (int j = i + 1; j < n - 1 && nums[j - 1] < nums[j]; j++) {
                nums[j] = nums[j - 1];
            }
        }
        return nums[0];
    }
};