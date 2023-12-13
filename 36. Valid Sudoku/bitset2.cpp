#include <bitset>
#include <vector>
using namespace std;

// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        vector<vector<bitset<n>>> seen(3, vector<bitset<n>>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int index = c - '1';
                    int block = i / 3 * 3 + j / 3;

                    if (seen[0][i][index] | seen[1][j][index] | seen[2][block][index]) {
                        return false;
                    }
                    seen[0][i][index] = seen[1][j][index] = seen[2][block][index] = 1;
                }
            }
        }

        return true;
    }
};