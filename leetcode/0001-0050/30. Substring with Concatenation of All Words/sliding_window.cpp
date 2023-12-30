#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words[0].size(), k = words.size();

        unordered_map<string, int> expected;
        for (string word : words) {
            expected[word]++;
        }

        vector<int> ans;
        for (int i = 0; i < m; i++) {
            unordered_map<string, int> seen;
            int seenWord = 0;
            for (int l = i, r = i; r <= n - m; r += m) {
                string wordR = s.substr(r, m);
                auto it = expected.find(wordR);
                if (it == expected.end()) {
                    l = r + m;
                    seen.clear();
                    seenWord = 0;
                } else if (seen[wordR] >= expected[wordR]) {
                    string wordL = s.substr(l, m);
                    while (wordL != wordR) {
                        seen[wordL]--;
                        seenWord--;
                        l += m;
                        wordL = s.substr(l, m);
                    }
                    l += m;
                } else {
                    seen[wordR]++;
                    seenWord++;
                    if (seenWord == k) {
                        ans.push_back(l);
                        string wordL = s.substr(l, m);
                        seen[wordL]--;
                        seenWord--;
                        l += m;
                    }
                }
            }
        }

        return ans;
    }
};