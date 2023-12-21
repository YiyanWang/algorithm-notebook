#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int hight) {
    int i = low, j = mid + 1;
    if (arr[i] <= arr[j]) return;

    while (i < j) {
        if (arr[i] <= arr[j]) {
            i++;
        } else {
            int value = arr[j];
            int index = j;

            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != i) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[i] = value;

            // Update all the pointers
            i++;
            mid++;
            j++;
        }
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array\n";
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}