#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n;
        m--;
        n--;

        if (m < 0) {
            nums1 = nums2;
            return;
        }

        while (i >= 0 && n >= 0) {
            if (m >= 0 && nums1[m] >= nums2[n]) {
                nums1[--i] = nums1[m--];
            } else {
                nums1[--i] = nums2[n--];
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = { 1, 3, 5, 0, 0, 0 };
    vector<int> nums2 = { 1, 4, 6 };
    solution.merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << endl;
    }
}