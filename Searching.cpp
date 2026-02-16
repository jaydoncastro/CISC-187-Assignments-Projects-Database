#include <iostream>
#include <vector>
using namespace std;

// Linear Search
int linearSearch(const vector<int>& arr, int key, int& comparisons) {
    comparisons = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(const vector<int>& arr, int key, int& comparisons) {
    int left = 0;
    int right = arr.size() - 1;
    comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    const int SIZE = 100000;
    vector<int> data;

    // Fill sorted array
    for (int i = 0; i < SIZE; i++) {
        data.push_back(i);
    }

    int key = 99999; // worst-case for linear search
    int linearComparisons, binaryComparisons;

    linearSearch(data, key, linearComparisons);
    binarySearch(data, key, binaryComparisons);

    cout << "Linear Search Comparisons: " << linearComparisons << endl;
    cout << "Binary Search Comparisons: " << binaryComparisons << endl;

    return 0;
}
