int main() {
    HashTable ht;

    // Insert at least 100 elements (using simple sequential keys for demo)
    cout << "=== Basic Test ===\n";
    for (int i = 1; i <= 120; ++i) {
        string key = "key" + to_string(i);
        ht.insert(key, i * 10);
    }

    ht.printTable();

    cout << "Search for key50: " << ht.search("key50") << endl;
    cout << "Search for key999 (non-existing): " << ht.search("key999") << endl;

    cout << "Remove key30: " << (ht.remove("key30") ? "Success" : "Failed") << endl;
    cout << "Remove key30 again: " << (ht.remove("key30") ? "Success" : "Failed") << endl;

    cout << "Final stats:\n";
    cout << "Capacity: " << ht.capacity << " | Elements: " << ht.size() 
         << " | Load: " << ht.loadFactor() << " | Collisions: " << ht.collisionCount << endl;

    return 0;
}
