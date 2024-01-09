#include <iostream>
using namespace std;

int partition(int arr[], int tag[], int low, int high) {
    int mid = low;

    while (low < high) {
        while (low < high && arr[tag[high]] >= arr[tag[mid]]) high--;
        while (low < high && arr[tag[low]] < arr[tag[mid]]) low++;
        swap(tag[high], tag[low]);
    }
    swap(tag[low], tag[mid]);

    return low;
}

void tagSort(int arr[], int tag[], int low, int high) {
    if (low >= high) return;

    int mid = partition(arr, tag, low, high);
    tagSort(arr, tag, low, mid - 1);
    tagSort(arr, tag, mid + 1, high);
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(int);
    int tag[6];
    for (int i = 0; i < n; i++) {
        tag[i] = i;
    }

    tagSort(arr, tag, 0, n - 1);

    cout << "Origin Array\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nSorted Array\n";
    for (int i = 0; i < n; i++) {
        cout << arr[tag[i]] << " ";
    }
    return 0;
}