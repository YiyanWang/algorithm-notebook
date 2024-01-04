#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/sum-absolute-differences-pairs-given-array/

//f(i) = f(i-1) + (f(i-1)-f(i-2)) + i * (a[i] - a[i-1])
int sumPairs(int arr[], int n) {
    int sum = 0, f0 = 0, f1 = 0;
    for (int i = 1; i < n; i++) {
        sum = 2 * f1 - f0 + i * (arr[i] - arr[i - 1]);
        f0 = f1;
        f1 = sum;
    }
    return sum;
}

int main() {
    int arr[] = { 1, 8, 9, 15, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sumPairs(arr, n) << endl;
    return 0;
}
