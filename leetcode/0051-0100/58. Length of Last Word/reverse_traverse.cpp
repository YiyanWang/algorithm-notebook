#include <string>
using namespace std;

// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                ans++;
            } else if (ans != 0) {
                break;
            }
        }

        return ans;
    }
};