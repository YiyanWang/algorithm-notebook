#include <vector>
using namespace std;

// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();

        int left = 0, right = n - 1;
        int low = 0, high = m - 1;

        vector<int> ans;
        while (left <= right && low <= high) {
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[low][j]);
            }
            if (low++ == high) {
                break;
            }

            for (int i = low; i <= high; i++) {
                ans.push_back(matrix[i][right]);
            }
            if (right-- == left) {
                break;
            }

            for (int j = right; j >= left; j--) {
                ans.push_back(matrix[high][j]);
            }
            high--;

            for (int i = high; i >= low; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }

        return ans;
    }
};