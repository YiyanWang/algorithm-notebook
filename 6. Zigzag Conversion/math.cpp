#include <string>
using namespace std;

// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        int depth = numRows - 1;
        if (depth == 0) {
            return s;
        }

        int n = s.size();
        int round = (n + depth - 2) / (2 * depth) + 1;

        string ans = "";
        for (int i = 0; i <= depth; i++) {
            for (int j = 0; j < round; j++) {
                int x1 = 2 * depth * j - i;
                int x2 = 2 * depth * j + i;
                if (x1 >= 0 && x1 < n && i != depth) {
                    ans += s[x1];
                }
                if (x2 < n && i != 0) {
                    ans += s[x2];
                }
            }
        }
        return ans;
    }
};