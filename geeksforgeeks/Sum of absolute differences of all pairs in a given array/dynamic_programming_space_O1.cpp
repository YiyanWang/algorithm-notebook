#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/sum-absolute-differences-pairs-given-array/

int sumPairs(int arr[], int n) {
    int sum = 0, dp = 0;
    for (int i = 1; i < n; i++) {
        dp += i * (arr[i] - arr[i - 1]);
        sum += dp;
    }
    return sum;
}

int main() {
    int arr[] = { 1, 8, 9, 15, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sumPairs(arr, n) << endl;
    return 0;
}
