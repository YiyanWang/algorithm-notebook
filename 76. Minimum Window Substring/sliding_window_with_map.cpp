#include <string>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();

        unordered_map<char, int> expected;
        for (char c : t) {
            expected[c]++;
        }

        unordered_map<char, int> seen;
        int count = 0;
        int minLen = INT_MAX, start = 0;
        for (int l = 0, r = 0; r < m; r++) {
            auto itR = expected.find(s[r]);
            if (itR == expected.end()) {
                if (count == 0) {
                    l++;
                }
            } else {
                seen[s[r]]++;
                if (seen[s[r]] <= itR->second) {
                    count++;
                }

                if (count == n) {
                    while (l < r) {
                        auto itL = seen.find(s[l]);
                        if (itL == seen.end()) {
                            l++;
                        } else if (itL->second > expected[s[l]]) {
                            l++;
                            itL->second--;
                        } else {
                            break;
                        }
                    }

                    int length = r - l + 1;
                    if (length < minLen) {
                        minLen = length;
                        start = l;
                    }

                    seen[s[l]]--;
                    count--;
                    l++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};