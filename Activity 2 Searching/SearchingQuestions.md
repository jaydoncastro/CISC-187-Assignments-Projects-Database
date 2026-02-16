1️⃣ Linear search steps for 8

Array: [2, 4, 6, 8, 10, 12, 13]

Linear search checks elements sequentially:

Compare 2 → not 8 (1)

Compare 4 → not 8 (2)

Compare 6 → not 8 (3)

Compare 8 → match (4)

Answer: 4 steps

2️⃣ Binary search steps for 8

Binary search on ordered array:

Indices: 0–6

Step 1:
Middle = index 3 → value = 8 → found immediately

Answer: 1 step

#include <iostream>
#include <vector>
#include <random>

using namespace std;

// =======================
// LINEAR SEARCH
// =======================
int linearSearch(const vector<int>& arr, int key, int& comparisons) {
    comparisons = 0;

    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

// =======================
// BINARY SEARCH
// =======================
int binarySearch(const vector<int>& arr, int key, int& comparisons) {
    int left = 0;
    int right = arr.size() - 1;
    comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

// =======================
// RANDOMIZED SEARCH
// =======================
int randomizedSearch(const vector<int>& data, int key, int& comparisons) {
    int n = data.size();
    vector<int> indices;

    // Create index list
    for (int i = 0; i < n; i++) {
        indices.push_back(i);
    }

    // Random generator
    random_device rd;
    mt19937 gen(rd());

    // Fisher-Yates shuffle
    for (int i = n - 1; i > 0; i--) {
        uniform_int_distribution<> dis(0, i);
        int j = dis(gen);

        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    comparisons = 0;

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (data[indices[i]] == key) {
            return indices[i];
        }
    }

    return -1;
}

// =======================
// MAIN
// =======================
int main() {

    const int SIZE = 100000;
    vector<int> data;

    // Fill sorted dataset
    for (int i = 0; i < SIZE; i++) {
        data.push_back(i);
    }

    int key = 99999;   // Worst-case for linear search
    int linearComparisons;
    int binaryComparisons;
    int randomComparisons;

    linearSearch(data, key, linearComparisons);
    binarySearch(data, key, binaryComparisons);
    randomizedSearch(data, key, randomComparisons);

    cout << "Dataset size: " << SIZE << endl;
    cout << "Searching for key: " << key << endl << endl;

    cout << "Linear Search Comparisons: " << linearComparisons << endl;
    cout << "Binary Search Comparisons: " << binaryComparisons << endl;
    cout << "Randomized Search Comparisons: " << randomComparisons << endl;

    return 0;
}
