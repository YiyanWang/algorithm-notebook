#include <string>
using namespace std;

// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        for (string str : strs) {
            for (int i = 0; i < common.size(); i++) {
                if (i > str.size() || str[i] != common[i]) {
                    common = common.substr(0, i);
                }
            }
        }
        return common;
    }
};