#include <vector>
using namespace std;

// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int loop = 0; loop < n / 2; loop++) {
            for (int i = loop; i < n - loop - 1; i++) {
                int temp = matrix[loop][i];
                matrix[loop][i] = matrix[n - 1 - i][loop];
                matrix[n - 1 - i][loop] = matrix[n - 1 - loop][n - 1 - i];
                matrix[n - 1 - loop][n - 1 - i] = matrix[i][n - 1 - loop];
                matrix[i][n - 1 - loop] = temp;
            }
        }
    }
};