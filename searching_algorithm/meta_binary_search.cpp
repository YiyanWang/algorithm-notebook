#include <iostream> 
using namespace std;

//Also called one-sided binary search by Steven Skiena in The Algorithm Design Manual on page 134
int metaBinarySearch(int arr[], int n, int target) {
    int shift = log2(n - 1) + 1;
    int index = 0;

    if (index < n && arr[index] == target) {
        return index;
    }

    while (shift >= 0) {
        int newIndex = index | (1 << shift--);
        //additional index out-of-bounds check, compared with binary search
        if (newIndex < n) {
            if (arr[newIndex] == target) {
                return newIndex;
            } else if (arr[newIndex] < target) {
                index = newIndex;
            }
        }
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int target = 10;
    int n = sizeof(arr) / sizeof(int);

    int result = metaBinarySearch(arr, n, target);
    if (result == -1)
        cout << "Element is not present in array" << endl;
    else
        cout << "Element is present at index " << result << endl;
    return 0;
}
