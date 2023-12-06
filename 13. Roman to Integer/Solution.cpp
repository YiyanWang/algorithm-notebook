#include <string>
#include <map>
using namespace std;

// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int n = s.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int previous = m[s[i - 1]];
            int current = m[s[i]];
            if (previous >= current) {
                ans += previous;
            } else {
                ans -= previous;
            }
        }
        ans += m[s[n - 1]];

        return ans;
    }
};