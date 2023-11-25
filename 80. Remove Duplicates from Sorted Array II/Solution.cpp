#include <vector>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        if (size <= 2)
        {
            return size;
        }

        int i = 2;
        for (int j = 2; j < size; j++)
        {
            if (nums[i - 2] != nums[j])
            {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};