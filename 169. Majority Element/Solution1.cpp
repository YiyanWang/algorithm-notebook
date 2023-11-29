#include <vector>
using namespace std;

// https://leetcode.com/problems/majority-element/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        _3WayQuickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() / 2];
    }

    void _3WayQuickSort(vector<int> &nums, int i, int j)
    {
        if (i >= j)
        {
            return;
        }

        int lt = i + 1;
        int gt = j;
        partition(nums, i, j, lt, gt);
        _3WayQuickSort(nums, i, lt - 1);
        _3WayQuickSort(nums, gt + 1, j);
    }

    void partition(vector<int> &nums, int i, int j, int &lt, int &gt)
    {
        int p = i++;
        while (i <= gt)
        {
            if (nums[i] == nums[p])
            {
                i++;
            }
            else if (nums[i] < nums[p])
            {
                swap(nums[i++], nums[lt++]);
            }
            else
            {
                swap(nums[i], nums[gt--]);
            }
        }
        if (--lt > p)
        {
            swap(nums[p], nums[lt]);
        }
    }

    void swap(int &i, int &j)
    {
        int temp = i;
        i = j;
        j = temp;
    }
};