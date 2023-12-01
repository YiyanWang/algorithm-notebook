#include <vector>
using namespace std;

// https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        int i = 0;
        int j = nums.size() - 1;
        int round = 0;
        int left = j - i - k + 1;
        if (left < k) {
            round++;
            k = left;
        }

        while (k > 0) {
            if (round % 2 == 0) {
                for (int n = 0; n < k; n++) {
                    swap(nums[j - k], nums[j--]);
                }
            } else {
                for (int n = 0; n < k; n++) {
                    swap(nums[i + k], nums[i++]);
                }
            }

            left = j - i - k + 1;
            if (left < k) {
                round++;
                k = left;
            }
        }
    }

    void swap(int& i, int& j) {
        int temp = i;
        i = j;
        j = temp;
    }
};