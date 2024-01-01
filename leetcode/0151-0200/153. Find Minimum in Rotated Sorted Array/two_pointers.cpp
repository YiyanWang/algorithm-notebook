#include <vector>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] < nums[right]) break;

            int mid = (left + right) / 2;
            if (nums[left] <= nums[mid]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};