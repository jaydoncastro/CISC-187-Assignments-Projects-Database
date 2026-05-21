# Project Activity

## Task 1: Players in Both Sports

**Goal:** Return the players who appear in both arrays using an \(O(N+M)\) approach.

### C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

struct Player {
    string first_name;
    string last_name;
    string team;
};

vector<string> playersInBothSports(const vector<Player>& basketball_players, const vector<Player>& football_players) {
    unordered_set<string> names;

    for (const auto& player : basketball_players) {
        names.insert(player.first_name + " " + player.last_name);
    }

    vector<string> result;
    for (const auto& player : football_players) {
        string full_name = player.first_name + " " + player.last_name;
        if (names.find(full_name) != names.end()) {
            result.push_back(full_name);
        }
    }

    return result;
}

int main() {
    vector<Player> basketball_players = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };

    vector<Player> football_players = {
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };

    vector<string> result = playersInBothSports(basketball_players, football_players);

    for (const string& name : result) {
        cout << name << endl;
    }

    return 0;
}
```

---

## Task 2: Missing Integer

**Goal:** Find the missing number from an array containing distinct integers from 0 to N in \(O(N)\) time.

### C++ Solution

```cpp
#include <iostream>
#include <vector>
using namespace std;

int findMissingInteger(const vector<int>& nums) {
    int n = nums.size();
    long long expected_sum = 1LL * n * (n + 1) / 2;
    long long actual_sum = 0;

    for (int num : nums) {
        actual_sum += num;
    }

    return static_cast<int>(expected_sum - actual_sum);
}

int main() {
    vector<int> nums1 = {2, 3, 0, 6, 1, 5};
    vector<int> nums2 = {8, 2, 3, 9, 4, 7, 5, 0, 6};

    cout << findMissingInteger(nums1) << endl; // 4
    cout << findMissingInteger(nums2) << endl; // 1

    return 0;
}
```

---

## Task 3: Maximum Stock Profit

**Goal:** Find the maximum profit from one buy and one sell in \(O(N)\) time.

### C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(const vector<int>& prices) {
    if (prices.size() < 2) return 0;

    int min_price = prices;
    int best_profit = 0;

    for (int price : prices) {
        if (price < min_price) {
            min_price = price;
        } else {
            best_profit = max(best_profit, price - min_price);
        }
    }

    return best_profit;
}

int main() {
    vector<int> prices = {10, 7, 5, 8, 11, 2, 6};
    cout << maxProfit(prices) << endl; // 6
    return 0;
}
```

---

## Task 4: Highest Product of Two Numbers

**Goal:** Find the greatest product of any two numbers in \(O(N)\) time, including negative values.

### C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int highestProductOfTwo(const vector<int>& nums) {
    if (nums.size() < 2) throw invalid_argument("Array must contain at least two numbers");

    int highest = max(nums, nums);[5]
    int lowest = min(nums, nums);[5]

    int highest_product = nums * nums;[5]

    for (size_t i = 2; i < nums.size(); ++i) {
        int current = nums[i];

        highest_product = max(highest_product,
                              max(current * highest, current * lowest));

        highest = max(highest, current);
        lowest = min(lowest, current);
    }

    return highest_product;
}

int main() {
    vector<int> nums = {5, -10, -6, 9, 4};
    cout << highestProductOfTwo(nums) << endl; // 60
    return 0;
}
```

---

## Task 5: Sort Temperatures

**Goal:** Sort temperature readings from 97.0 to 99.0 with one decimal place in \(O(N)\) time.

### C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<double> sortTemperatures(const vector<double>& temps) {
    const int min_temp = 970;
    const int max_temp = 990;
    const int range = max_temp - min_temp + 1;

    vector<int> counts(range, 0);

    for (double temp : temps) {
        int scaled = static_cast<int>(temp * 10 + 0.5);
        counts[scaled - min_temp]++;
    }

    vector<double> sorted;
    for (int i = 0; i < range; ++i) {
        while (counts[i] > 0) {
            sorted.push_back((min_temp + i) / 10.0);
            counts[i]--;
        }
    }

    return sorted;
}

int main() {
    vector<double> temps = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};

    vector<double> sorted = sortTemperatures(temps);

    for (double t : sorted) {
        cout << fixed << setprecision(1) << t << " ";
    }
    cout << endl;

    return 0;
}
```

---

## Task 6: Longest Consecutive Sequence

**Goal:** Find the length of the longest consecutive integer sequence in \(O(N)\) time.

### C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestConsecutiveSequence(const vector<int>& nums) {
    unordered_set<int> values(nums.begin(), nums.end());
    int longest = 0;

    for (int num : values) {
        if (values.find(num - 1) == values.end()) {
            int current = num;
            int streak = 1;

            while (values.find(current + 1) != values.end()) {
                current++;
                streak++;
            }

            longest = max(longest, streak);
        }
    }

    return longest;
}

int main() {
    vector<int> nums1 = {10, 5, 12, 3, 55, 30, 4, 11, 2};
    vector<int> nums2 = {19, 13, 15, 12, 18, 14, 17, 11};

    cout << longestConsecutiveSequence(nums1) << endl; // 4
    cout << longestConsecutiveSequence(nums2) << endl; // 5

    return 0;
}
```
