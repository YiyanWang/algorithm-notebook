#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = low++;
    while (low < high) {
        while (low < high && arr[high] >= arr[pivot]) high--;
        while (low < high && arr[low] < arr[pivot]) low++;
        swap(arr[low], arr[high]);
    }
    swap(arr[pivot], arr[low]);
    return low;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array\n";
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}