using namespace std;

// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

class Solution {
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int target) {
        int left = 0, right = n - 1;

        //find left bound
        int leftBound = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > target) {
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                if (mid > 0 && arr[mid - 1] == target) {
                    right = mid - 1;
                } else {
                    leftBound = mid;
                    break;
                }
            }
        }
        if (leftBound == -1) {
            return 0;
        }

        //find right bound
        int rightBound = -1;
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > target) {
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                if (mid < n - 1 && arr[mid + 1] == target) {
                    left = mid + 1;
                } else {
                    rightBound = mid;
                    break;
                }
            }
        }

        return rightBound - leftBound + 1;
    }
};