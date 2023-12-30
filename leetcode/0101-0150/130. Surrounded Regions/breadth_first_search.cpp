#include <queue>
#include <vector>
using namespace std;

// https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if (board[i][j] == 'O') {
                        bfs(board, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void bfs(vector<vector<char>> &board, int i, int j) {
        int m = board.size(), n = board[0].size();
        int offset[] = { 0, 1, 0, -1, 0 };
        queue<pair<int, int>> q;
        q.push({ i, j });
        board[i][j] = 'Y';

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            i = p.first, j = p.second;

            for (int k = 0; k < 4; k++) {
                int a = i + offset[k];
                int b = j + offset[k + 1];
                if (a >= 0 && a < m && b >= 0 && b < n && board[a][b] == 'O') {
                    board[a][b] = 'Y';
                    q.push({ a, b });
                }
            }
        }
    }
};