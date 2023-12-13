#include <functional>
#include <vector>
using namespace std;

// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        auto calNeighbor = [&](int i, int j) {
            int count = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                if (x < 0) continue;
                if (x >= m) break;

                for (int y = j - 1; y <= j + 1; y++) {
                    if (y < 0) continue;
                    if (y >= n) break;
                    if (x == i && y == j) continue;

                    if (board[x][y] > 0) {
                        count++;
                    }
                }
            }
            return count;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int neighbor = calNeighbor(i, j);
                if (board[i][j] == 0) {
                    if (neighbor == 3) {
                        board[i][j] = -1;
                    }
                } else {
                    if (neighbor < 2 || neighbor > 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 1;
                } else if (board[i][j] == 2) {
                    board[i][j] = 0;
                }
            }
        }
    }
};