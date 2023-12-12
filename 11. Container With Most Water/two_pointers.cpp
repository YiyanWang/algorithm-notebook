#include <vector>
using namespace std;

// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int l = 0, r = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            l = max(l, height[i]);
            r = max(r, height[j]);
            if (l > r) {
                water = max(water, r * (j - i));
                j--;
            } else {
                water = max(water, l * (j - i));
                i++;
            }
        }
        return water;
    }
};