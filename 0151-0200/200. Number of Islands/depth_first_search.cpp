#include <vector>
using namespace std;

// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int m, n;
    int numIslands(vector<vector<char>> &grid) {
        m = grid.size(), n = grid[0].size();

        int island = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    dfs(grid, i, j);
                }
            }
        }

        return island;
    }

    void dfs(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '0';
        if (i > 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if (i < m - 1 && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if (j > 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        if (j < n - 1 && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
    }
};