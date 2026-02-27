#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 50;

int countAdjacentInversions(vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        if (arr[i] > arr[i + 1])
            count++;
    }
    return count;
}

int main() {
    vector<int> arr(SIZE);

    cout << "Enter 50 integers:\n";
    for (int i = 0; i < SIZE; i++)
        cin >> arr[i];

    int inversions = countAdjacentInversions(arr);

    if (inversions >= 44)
        cout << "Worst Case\n";
    else
        cout << "Average Case\n";

    return 0;
}
