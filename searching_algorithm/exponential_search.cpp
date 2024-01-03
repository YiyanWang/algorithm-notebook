#include <iostream> 
using namespace std;

//find right + binary search
int exponentialSearch(int arr[], int target) {
    int right = 1;
    while (arr[right] < target) right <<= 1;
    int left = right >> 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int target = 40;

    int result = exponentialSearch(arr, target);
    if (result == -1)
        cout << "Element is not present in array" << endl;
    else
        cout << "Element is present at index " << result << endl;
    return 0;
}
