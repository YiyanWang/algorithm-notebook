#include <vector>
using namespace std;

// https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int h = 0;
        for (int i = 0; i < n; i++) {
            if (citations[i] != 0) {
                h = n - i;
                if (h <= citations[i]) {
                    break;
                }
            }
        }
        return h;
    }
};