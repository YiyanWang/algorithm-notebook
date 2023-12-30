#include <string>
using namespace std;

// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n == 0) {
            return true;
        }

        for (int i = 0, j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                i++;
                if (i == n) {
                    return true;
                }
            }
        }

        return false;
    }
};