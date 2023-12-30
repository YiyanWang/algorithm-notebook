#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();

        vector<int> expected(128, 0);
        for (char c : t) {
            expected[c]++;
        }

        int count = 0;
        int minLen = INT_MAX, start = 0;
        for (int l = 0, r = 0; r < m; r++) {
            if (expected[s[r]]-- > 0) {
                count++;
            }

            if (count == n) {
                while (expected[s[l]] < 0) {
                    expected[s[l]]++;
                    l++;
                }

                int length = r - l + 1;
                if (length < minLen) {
                    minLen = length;
                    start = l;
                }

                expected[s[l]]++;
                l++;
                count--;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};