#include <string>
using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        string ans = "";
        int start = -1;
        int min = s.size() - 1;
        int max = 0;
        for (int i = 0; i < s.size(); i++) {
            if (start >= 0) {
                if (s[i] == ' ') {
                    reverse(s.begin() + start, s.begin() + i);
                    ans += s.substr(start, i + 1 - start);
                    start = -1;
                    if (i > max) {
                        max = i;
                    }
                }
            } else if (s[i] != ' ') {
                start = i;
                if (i < min) {
                    min = i;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans.substr(1, ans.size() - 1);
    }
};