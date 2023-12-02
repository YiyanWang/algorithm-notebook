#include <vector>
using namespace std;

// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n, 1);

        int prefixProduct = 1;
        int suffixProduct = 1;
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            results[i] *= prefixProduct;
            prefixProduct *= nums[i];

            results[j] *= suffixProduct;
            suffixProduct *= nums[j];
        }

        return results;
    }
};