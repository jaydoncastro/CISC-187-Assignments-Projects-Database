#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 50;

// Count adjacent inversions
int countAdjacentInversions(vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        if (arr[i] > arr[i + 1])
            count++;
    }
    return count;
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < SIZE; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr(SIZE);

    cout << "Enter 50 integers:\n";
    for (int i = 0; i < SIZE; i++)
        cin >> arr[i];

    int inversions = countAdjacentInversions(arr);

    if (inversions <= 5) {
        cout << "Best case detected (Nearly Sorted)\n";
        cout << "Using Insertion Sort\n";
        insertionSort(arr);
    }
    else if (inversions >= 44) {
        cout << "Worst case detected (Reverse Sorted)\n";
        cout << "Using Selection Sort\n";
        selectionSort(arr);
    }
    else {
        cout << "Average case detected\n";
        cout << "Using Selection Sort\n";
        selectionSort(arr);
    }

    cout << "Sorted Array:\n";
    for (int num : arr)
        cout << num << " ";

    return 0;
}
