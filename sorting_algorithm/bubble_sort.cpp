#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int j = n; j > 0; j--) {
        for (int i = 1; i < j; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
            }
        }
    }
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);

    cout << "Sorted Array\n";
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}