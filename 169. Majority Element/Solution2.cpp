#include <vector>
using namespace std;

// https://leetcode.com/problems/majority-element/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Boyer–Moore majority vote algorithm
        int majority = nums[0];
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == majority)
            {
                count++;
            }
            else if (count-- == 0)
            {
                majority = nums[i];
                count = 1;
            }
        }

        return majority;
    }
};