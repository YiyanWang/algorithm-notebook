#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> table(m + 1, vector(26, -1));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                table[i][j] = table[i + 1][j];
            }

            int index = t[i] - 'a';
            table[i][index] = i + 1;
        }

        for (int i = 0, j = 0; i < n; i++) {
            int index = s[i] - 'a';
            j = table[j][index];
            if (j == -1) {
                return false;
            }
        }
        return true;
    }
};