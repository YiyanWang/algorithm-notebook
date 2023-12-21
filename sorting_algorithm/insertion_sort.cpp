#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int val = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > val) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = val;
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);

    cout << "Sorted Array\n";
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}