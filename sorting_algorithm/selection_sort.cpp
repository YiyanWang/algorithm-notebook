#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = min + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(int);

    selectionSort(arr, n);

    cout << "Sorted Array\n";
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}