#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> available(26);
        for (char c : magazine) {
            available[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (available[c - 'a']-- == 0) {
                return false;
            }
        }

        return true;
    }
};