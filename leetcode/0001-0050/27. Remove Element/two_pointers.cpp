#include <vector>
using namespace std;

// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                if (i != j) {
                    nums[j] = nums[i];
                }
                j++;
            }
        }
        return j;
    }
};