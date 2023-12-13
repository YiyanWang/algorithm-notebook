#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size();
        int m = pattern.size();

        vector<int> charIndex(26);
        unordered_map<string, int> wordIndex;

        int i = 0;
        istringstream iss(s);
        for (string word; iss >> word; i++) {
            if (i == m) {
                return false;
            }

            int c = pattern[i] - 'a';
            if (charIndex[c] != wordIndex[word]) {
                return false;
            }

            charIndex[c] = i + 1;
            wordIndex[word] = i + 1;
        }

        return i == m;
    }
};