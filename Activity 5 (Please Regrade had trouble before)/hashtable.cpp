# Implementing a Hash Table with Separate Chaining

## Part 1–4: HashTable Implementation

Below is the complete C++ implementation of the `HashTable` class using separate chaining, polynomial rolling hash, collision counting, and dynamic resizing.

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>   // for std::pair
#include <cctype>    // for std::tolower (optional normalization)

using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table;
    int currentSize;      // number of key-value pairs
    int capacity;         // number of buckets
    int collisionCount;   // number of times we insert into non-empty bucket

    int hashFunction(const string& key) const {
        const int prime = 31;
        long long hash = 0;

        for (char ch : key) {
            char c = tolower(ch);  // case-insensitive hashing (optional but improves distribution)
            hash = hash * prime + static_cast<unsigned char>(c);
        }

        return static_cast<int>(hash % capacity);
    }

    void rehash() {
        int oldCapacity = capacity;
        capacity *= 2;

        vector<list<pair<string, int>>> newTable(capacity);

        // Reinsert all existing elements
        for (int i = 0; i < oldCapacity; ++i) {
            for (const auto& p : table[i]) {
                int newIndex = hashFunction(p.first);
                newTable[newIndex].push_back(p);
            }
        }

        table = move(newTable);

        // Note: We do NOT reset collisionCount here — it accumulates across the entire run
        // as a measure of overall collision behavior. Resetting would hide history.
    }

public:
    HashTable(int size = 11) 
        : table(size), currentSize(0), capacity(size), collisionCount(0) {}

    void insert(const string& key, int value) {
        if (loadFactor() > 0.75) {
            rehash();
        }

        int index = hashFunction(key);
        auto& chain = table[index];

        // Check if key already exists → update value
        for (auto& p : chain) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }

        // New key → add to chain
        chain.emplace_back(key, value);
        ++currentSize;

        // Collision if chain was not empty before insert
        if (chain.size() > 1) {
            ++collisionCount;
        }
    }

    bool remove(const string& key) {
        int index = hashFunction(key);
        auto& chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);
                --currentSize;
                return true;
            }
        }
        return false;
    }

    int search(const string& key) const {
        int index = hashFunction(key);
        const auto& chain = table[index];

        for (const auto& p : chain) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;  // Not found (could throw exception instead)
    }

    double loadFactor() const {
        return static_cast<double>(currentSize) / capacity;
    }

    int size() const {
        return currentSize;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    void printTable() const {
        cout << "Hash Table (capacity = " << capacity << ", size = " << currentSize 
             << ", load = " << loadFactor() << ", collisions = " << collisionCount << "):\n";
        for (int i = 0; i < capacity; ++i) {
            if (!table[i].empty()) {
                cout << "Bucket " << i << ": ";
                for (const auto& p : table[i]) {
                    cout << "(" << p.first << ", " << p.second << ") ";
                }
                cout << "\n";
            }
        }
        cout << endl;
    }

    // Extra: get max chain length and avg chain length for analysis
    int maxBucketSize() const {
        int maxLen = 0;
        for (const auto& chain : table) {
            maxLen = max(maxLen, static_cast<int>(chain.size()));
        }
        return maxLen;
    }

    double avgBucketLength() const {
        if (currentSize == 0) return 0.0;
        int totalLen = 0;
        int nonEmpty = 0;
        for (const auto& chain : table) {
            if (!chain.empty()) {
                totalLen += chain.size();
                ++nonEmpty;
            }
        }
        return nonEmpty > 0 ? static_cast<double>(totalLen) / nonEmpty : 0.0;
    }
};
