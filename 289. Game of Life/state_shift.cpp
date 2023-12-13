#include <vector>
using namespace std;

// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int x = max(i - 1, 0); x <= min(i + 1, m - 1); x++) {
                    for (int y = max(j - 1, 0); y <= min(j + 1, n - 1); y++) {
                        count += board[x][y] & 1;
                    }
                }

                if (count == 3 || count - board[i][j] == 3) {
                    board[i][j] |= 2;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};