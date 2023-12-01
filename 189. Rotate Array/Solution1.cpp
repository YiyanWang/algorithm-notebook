#include <vector>
using namespace std;

// https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        if (k == 0) {
            return;
        }

        reverse(nums, 0, size - k - 1);
        reverse(nums, size - k, size - 1);
        reverse(nums, 0, size - 1);
    }

    void reverse(vector<int>& nums, int i, int j) {
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }

    void swap(int& i, int& j) {
        int temp = i;
        i = j;
        j = temp;
    }
};