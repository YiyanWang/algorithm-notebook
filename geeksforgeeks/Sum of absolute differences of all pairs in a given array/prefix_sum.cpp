#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/sum-absolute-differences-pairs-given-array/

int sumPairs(int arr[], int n) {
    int sum = 0, prefix = 0, suffix = 0;
    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        sum += (2 * (i + 1) - n) * arr[i] - prefix + suffix;
        suffix += arr[n - 1 - i];
    }
    return sum / 2;
}

int main() {
    int arr[] = { 1, 8, 9, 15, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sumPairs(arr, n) << endl;
    return 0;
}
