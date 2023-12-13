#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> groupIndex;
        vector<vector<string>> anagrams;

        int i = 0;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            auto it = groupIndex.find(key);
            if (it == groupIndex.end()) {
                anagrams.push_back({ str });
                groupIndex[key] = i++;
            } else {
                anagrams[it->second].push_back(str);
            }
        }

        return anagrams;
    }
};