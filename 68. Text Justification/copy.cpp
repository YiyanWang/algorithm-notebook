#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> candidates;
        int left = maxWidth;

        vector<string> ans;
        for (int i = 0; i < n; i++) {
            string word = words[i];
            if (word.size() + candidates.size() > left) {
                int quotient = 0;
                int remainder = left;
                if (candidates.size() > 1) {
                    quotient = left / (candidates.size() - 1);
                    remainder = left % (candidates.size() - 1);
                }

                string line = string(maxWidth, ' ');
                copy(candidates[0].begin(), candidates[0].end(), line.begin());
                for (int j = 1, pos = candidates[0].size(); j < candidates.size(); j++) {
                    pos += quotient + (remainder-- > 0);
                    copy(candidates[j].begin(), candidates[j].end(), line.begin() + pos);
                    pos += candidates[j].size();
                }
                ans.push_back(line);

                left = maxWidth;
                candidates.clear();
            }

            candidates.push_back(word);
            left -= word.size();
        }

        string line = string(maxWidth, ' ');
        copy(candidates[0].begin(), candidates[0].end(), line.begin());
        for (int j = 1, pos = candidates[0].size(); j < candidates.size(); j++) {
            pos += 1;
            copy(candidates[j].begin(), candidates[j].end(), line.begin() + pos);
            pos += candidates[j].size();
        }
        ans.push_back(line);

        return ans;
    }
};