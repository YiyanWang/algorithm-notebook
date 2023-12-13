#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == t) {
            return true;
        }

        vector<int> counter(26);
        for (char c : s) {
            counter[c - 'a']++;
        }
        for (char c : t) {
            if (counter[c - 'a']-- == 0) {
                return false;
            }
        }

        for (int count : counter) {
            if (count > 0) {
                return false;
            }
        }

        return true;
    }
};