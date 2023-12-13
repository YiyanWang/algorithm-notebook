#include <vector>
using namespace std;

// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        for (int i = 0; i < n; i++) {
            vector<int> seenRow(n, 0);
            vector<int> seenColumn(n, 0);
            vector<int> seenBlock(n, 0);

            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    int index = board[i][j] - '1';
                    if (seenRow[index] == 1) {
                        return false;
                    } else {
                        seenRow[index]++;
                    }
                }

                if (board[j][i] != '.') {
                    int index = board[j][i] - '1';
                    if (seenColumn[index] == 1) {
                        return false;
                    } else {
                        seenColumn[index]++;
                    }
                }

                int iBlock = i / 3 * 3 + j / 3;
                int jBlock = i % 3 * 3 + j % 3;
                if (board[iBlock][jBlock] != '.') {
                    int index = board[iBlock][jBlock] - '1';
                    if (seenBlock[index] == 1) {
                        return false;
                    } else {
                        seenBlock[index]++;
                    }
                }
            }
        }

        return true;
    }
};