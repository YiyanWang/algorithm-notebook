#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/sum-absolute-differences-pairs-given-array/

int sumPairs(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i * arr[i] - (n - 1 - i) * arr[i];
    }
    return sum;
}

int main() {
    int arr[] = { 1, 8, 9, 15, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sumPairs(arr, n) << endl;
    return 0;
}
