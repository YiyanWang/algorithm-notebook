#include <queue>
#include <vector>
using namespace std;

// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();

        int island = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    bfs(grid, i, j);
                }
            }
        }

        return island;
    }

    void bfs(vector<vector<char>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({ i, j });
        grid[i][j] = '0';

        while (!q.empty()) {
            pair<int, int> p = q.front();
            i = p.first, j = p.second;
            q.pop();

            if (i > 0 && grid[i - 1][j] == '1') {
                grid[i - 1][j] = '0';
                q.push({ i - 1, j });
            }
            if (i < m - 1 && grid[i + 1][j] == '1') {
                grid[i + 1][j] = '0';
                q.push({ i + 1, j });
            }
            if (j > 0 && grid[i][j - 1] == '1') {
                grid[i][j - 1] = '0';
                q.push({ i, j - 1 });
            }
            if (j < n - 1 && grid[i][j + 1] == '1') {
                grid[i][j + 1] = '0';
                q.push({ i, j + 1 });
            }
        }
    }
};