#include <vector>
using namespace std;

// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2;) {
            if (nums[i] > 0) {
                break;
            }

            for (int j = i + 1, k = n - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> triplet = { nums[i], nums[j], nums[k] };
                    ans.push_back(triplet);
                    do {
                        j++;
                    } while (nums[j] == nums[j - 1] && j < k);
                    do {
                        k--;
                    } while (nums[k] == nums[k + 1] && j < k);
                }
            }

            do {
                i++;
            } while (nums[i] == nums[i - 1] && i < n - 2);
        }
        return ans;
    }
};