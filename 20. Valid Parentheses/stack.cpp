#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        unordered_map<char, char> map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        vector<char> parentheses;
        for (char c : s) {
            if (map.count(c)) {
                if (parentheses.size() == 0) {
                    return false;
                }
                char back = parentheses.back();
                parentheses.pop_back();
                if (back != map[c]) {
                    return false;
                }
            } else {
                parentheses.push_back(c);
            }
        }

        return parentheses.size() == 0;
    }
};