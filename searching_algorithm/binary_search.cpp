#include <iostream> 
using namespace std;

// 二分查找，要求数组arr必须有序
int binarySearch(const int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // 避免溢出
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int target = 10;
    int n = sizeof(arr) / sizeof(int);

    int result = binarySearch(arr, n, target);
    if (result == -1)
        cout << "Element is not present in array" << endl;
    else
        cout << "Element is present at index " << result << endl;
    return 0;
}
