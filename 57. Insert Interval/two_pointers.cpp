#include <vector>
using namespace std;

// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> ans;
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (l == -1 && newInterval[0] <= intervals[i][1]) {
                l = min(newInterval[0], intervals[i][0]);
                if (newInterval[1] < intervals[i][0]) {
                    r = newInterval[1];
                    ans.push_back({ l, r });
                }
            }

            if (l == -1 || r != -1) {
                ans.push_back(intervals[i]);
            } else if (i == n - 1 || newInterval[1] < intervals[i + 1][0]) {
                r = max(newInterval[1], intervals[i][1]);
                ans.push_back({ l, r });
            }
        }
        if (l == -1 && r == -1) {
            ans.push_back(newInterval);
        }

        return ans;
    }
};