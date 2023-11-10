#include <iostream>
using namespace std;

// Binary search for sorted array
int binarySearchSorted(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Element not found
}

// Binary search for unsorted array
int binarySearchUnsorted(int arr[], int size, int target) {
    sort(arr, arr + size); // Sort the array first

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Element not found
}

int main() {
    int sortedArr[] = {2, 4, 6, 8, 10};
    int unsortedArr[] = {10, 6, 2, 8, 4};
    int target = 8;

    int sortedIndex = binarySearchSorted(sortedArr, 0, sizeof(sortedArr) / sizeof(sortedArr[0]) - 1, target);
    int unsortedIndex = binarySearchUnsorted(unsortedArr, sizeof(unsortedArr) / sizeof(unsortedArr[0]), target);

    if (sortedIndex != -1)
        cout << "Element found at index " << sortedIndex << " in the sorted array." << std::endl;
    else
        cout << "Element not found in the sorted array." << endl;

    if (unsortedIndex != -1)
        cout << "Element found at index " << unsortedIndex << " in the unsorted array." << std::endl;
    else
        cout << "Element not found in the unsorted array." << endl;

    return 0;
}