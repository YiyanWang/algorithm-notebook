#include <bitset>
#include <functional>
#include <vector>
using namespace std;

// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;

        auto mapper = [](int i, int j) { return pair(i, j); };
        auto reverseMapper = [](int i, int j) { return pair(j, i); };
        auto blockMapper = [](int i, int j) {
            int iBlock = i / 3 * 3 + j / 3;
            int jBlock = i % 3 * 3 + j % 3;
            return pair(iBlock, jBlock);
        };
        vector<function<pair<int, int>(int, int)>> mappers = { mapper, reverseMapper, blockMapper };

        for (function<pair<int, int>(int, int)> mapper : mappers) {
            for (int i = 0; i < n; i++) {
                bitset<n> seen;
                for (int j = 0; j < n; j++) {
                    pair<int, int> indices = mapper(i, j);
                    char c = board[indices.first][indices.second];
                    if (c != '.') {
                        int index = c - '1';
                        if (seen[index]) {
                            return false;
                        } else {
                            seen[index] = 1;
                        }
                    }
                }
            }
        }

        return true;
    }
};