#include <vector>
using namespace std;

// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> traps(n);

        int max = 0;
        for (int i = 0; i < n; i++) {
            traps[i] = max;
            if (height[i] > max) {
                max = height[i];
            }
        }

        max = 0;
        int water = 0;
        for (int i = n - 1; i >= 0; i--) {
            int trap = std::min(traps[i], max);
            water += std::max(0, trap - height[i]);
            if (height[i] > max) {
                max = height[i];
            }
        }
        return water;
    }
};