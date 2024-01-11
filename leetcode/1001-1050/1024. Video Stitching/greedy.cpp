#include <vector>
using namespace std;

// https://leetcode.com/problems/video-stitching/

class Solution {
public:
    int videoStitching(vector<vector<int>> &clips, int time) {
        sort(clips.begin(), clips.end());

        int n = clips.size();
        int count = 0, current = 0, reachable = 0;
        for (int i = 0; i < n; i++) {
            vector<int> clip = clips[i];

            if (clip[0] <= current) {
                reachable = max(reachable, clip[1]);
            } else if (clip[0] > reachable) {
                return -1;
            } else {
                count++;
                current = reachable;
                reachable = clip[1];
            }

            if (reachable >= time) {
                break;
            }
        }

        if (reachable > current) {
            count++;
            current = reachable;
        }
        if (current < time) return -1;
        return count;
    }
};