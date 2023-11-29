#include <vector>
using namespace std;

// https://leetcode.com/problems/majority-element/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() / 2];
    }

    void quickSort(vector<int> &nums, int i, int j)
    {
        if (i >= j)
        {
            return;
        }

        int p = partition(nums, i, j);
        quickSort(nums, i, p - 1);
        quickSort(nums, p + 1, j);
    }

    int partition(vector<int> &nums, int i, int j)
    {
        int p = i;
        while (i < j)
        {
            while (i < j && nums[i] <= nums[p])
            {
                i++;
            }
            while (i < j && nums[j] > nums[p])
            {
                j--;
            }
            if (i < j && nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
            }
        }
        if (nums[p] > nums[i])
        {
            swap(nums[p], nums[i]);
        }
        return i;
    }

    void swap(int &i, int &j)
    {
        int temp = i;
        i = j;
        j = temp;
    }
};