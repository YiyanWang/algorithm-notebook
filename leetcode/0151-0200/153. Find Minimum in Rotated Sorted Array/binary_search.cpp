#include <vector>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int mid = n / 2, delta = mid;
        while (delta > 0) {
            int left = max(0, mid - delta);
            int right = min(n - 1, mid + delta);

            int smallest = nums[mid];
            if (nums[left] < smallest) {
                smallest = nums[left];
                mid = left;
            }
            if (nums[right] < smallest) {
                mid = right;
            }

            if (delta == 1) break;
            delta = (delta + 1) / 2;
        }

        return nums[mid];
    }
};