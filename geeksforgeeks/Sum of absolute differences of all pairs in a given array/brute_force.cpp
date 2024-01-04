#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/sum-absolute-differences-pairs-given-array/

int sumPairs(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += abs(arr[i] - arr[j]);
        }
    }
    return sum;
}

int main() {
    int arr[] = { 1, 8, 9, 15, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sumPairs(arr, n) << endl;
    return 0;
}
