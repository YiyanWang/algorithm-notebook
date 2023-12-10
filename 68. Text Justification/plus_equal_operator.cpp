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

                string delimiter = "";
                for (int j = 0; j < quotient; j++) {
                    delimiter += " ";
                }

                string line = candidates.front();
                for (int j = 1; j < candidates.size(); j++) {
                    if (remainder-- > 0) {
                        line += " ";
                    }
                    line += delimiter;
                    line += candidates[j];
                }
                while (remainder-- > 0) {
                    line += " ";
                }
                ans.push_back(line);

                left = maxWidth;
                candidates.clear();
            }

            candidates.push_back(word);
            left -= word.size();
        }

        string line = candidates.front();
        for (int j = 1; j < candidates.size(); j++) {
            line += " ";
            line += candidates[j];
        }
        while (line.size() < maxWidth) {
            line += " ";
        }
        ans.push_back(line);

        return ans;
    }
};