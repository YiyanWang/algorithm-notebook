#include <iostream> 
using namespace std;

int sentinelSearch(int arr[], int n, int target) {
    int last = arr[n - 1];
    arr[n - 1] = target;

    int i = 0;
    //There is no index out of bounds check.
    //Sentinel search performs N + 2 comparisons, while linear search performs 2 * N comparisons.
    while (arr[i] != target)
        i++;

    if (i < n - 1 || last == target)
        return i;
    else
        return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int target = 10;
    int n = sizeof(arr) / sizeof(int);

    int result = sentinelSearch(arr, n, target);
    if (result == -1)
        cout << "Element is not present in array" << endl;
    else
        cout << "Element is present at index " << result << endl;
    return 0;
}
