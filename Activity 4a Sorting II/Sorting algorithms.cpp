#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
===========================================================
PART 1: Average-Case Proof (Insertion Sort is O(N^2))

In the average case, each element moves about halfway
through the sorted portion.

Total comparisons:

1 + 2 + 3 + ... + (N-1)

This sum equals:

N(N-1)/2

Expands to:

(N^2 - N)/2

The dominant term is N^2.

Therefore:

Time Complexity = O(N^2)
===========================================================
*/


// PART 2: Worst-case operation counter (N = 5)
// Counts comparisons + shifts
void insertionSortWorstCase(vector<int>& arr, int& comparisons, int& shifts) {
    comparisons = 0;
    shifts = 0;

    int N = arr.size();

    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;

            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            } else {
                break;
            }
        }

        arr[j + 1] = key;
    }
}


// PART 3: Original containsX (inefficient)
bool containsX_original(string str) {
    bool foundX = false;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'X') {
            foundX = true;
        }
    }

    return foundX;
}


// PART 3b: Improved containsX (early exit)
bool containsX_improved(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'X') {
            return true;  // stop immediately
        }
    }
    return false;
}


int main() {

    cout << "===== INSERTION SORT WORST CASE TEST (N=5) =====\n";

    // Worst case array (reverse sorted)
    vector<int> arr = {5, 4, 3, 2, 1};

    int comparisons = 0;
    int shifts = 0;

    insertionSortWorstCase(arr, comparisons, shifts);

    cout << "Comparisons: " << comparisons << endl;
    cout << "Shifts: " << shifts << endl;
    cout << "Total Operations: " << comparisons + shifts << endl;

    cout << "\n(Should equal 20 for worst case N=5)\n\n";


    cout << "===== containsX TEST =====\n";

    string test1 = "HELLO";
    string test2 = "HEXXO";

    cout << "Original containsX (HELLO): "
         << containsX_original(test1) << endl;

    cout << "Original containsX (HEXXO): "
         << containsX_original(test2) << endl;

    cout << "\nImproved containsX (HELLO): "
         << containsX_improved(test1) << endl;

    cout << "Improved containsX (HEXXO): "
         << containsX_improved(test2) << endl;


    /*
    PART 3 ANSWERS:

    (a) Time Complexity:
        O(N)
        Because the loop may scan the entire string.

    (b) Improvement:
        Returning immediately when 'X' is found
        improves best-case to O(1).
        Worst-case remains O(N).
    */

    return 0;
}
