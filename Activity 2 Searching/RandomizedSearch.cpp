#include <iostream>
#include <vector>
#include <random>

using namespace std;

int randomizedSearch(vector<int>& data, int key, int& comparisons) {
    int n = data.size();
    vector<int> indices;

    for (int i = 0; i < n; i++)
        indices.push_back(i);

    random_device rd;
    mt19937 gen(rd());

    // Fisher-Yates shuffle
    for (int i = n - 1; i > 0; i--) {
        uniform_int_distribution<> dis(0, i);
        int j = dis(gen);
        swap(indices[i], indices[j]);
    }

    comparisons = 0;

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (data[indices[i]] == key)
            return indices[i];
    }

    return -1;
}

int main() {
    const int SIZE = 100000;
    vector<int> data;

    for (int i = 0; i < SIZE; i++)
        data.push_back(i);

    int key = 99999;
    int comparisons;

    randomizedSearch(data, key, comparisons);

    cout << "Randomized Search Comparisons: " << comparisons << endl;

    return 0;
}
