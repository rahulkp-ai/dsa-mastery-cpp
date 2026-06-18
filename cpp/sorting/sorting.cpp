/**
 * Sorting Algorithms - C++20
 * ============================
 * All classic sorting with modern C++ features.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

namespace dsa {

// Merge Sort - O(n log n), stable
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int x = 0; x < k; ++x) arr[left + x] = temp[x];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Quick Sort - O(n log n) avg, O(n²) worst
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            std::swap(arr[++i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

} // namespace dsa

int main() {
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> arr2 = arr1;

    dsa::mergeSort(arr1, 0, arr1.size() - 1);
    std::cout << "Merge Sort: ";
    for (int x : arr1) std::cout << x << " ";
    std::cout << "\n";

    dsa::quickSort(arr2, 0, arr2.size() - 1);
    std::cout << "Quick Sort: ";
    for (int x : arr2) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
