#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        vector<int> table(256, -1);

        int ans = 0;
        while (r < n) {
            int index = table[s[r]];
            if (index >= l) {
                l = index + 1;
            } else {
                ans = max(ans, r - l + 1);
            }
            table[s[r]] = r;
            r++;
        }

        return ans;
    }
};