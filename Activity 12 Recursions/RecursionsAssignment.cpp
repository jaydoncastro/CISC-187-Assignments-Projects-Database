# Recursions Assignment (C++)

## 1. Base Case Identification

### Given Function (C++ Equivalent)

```
#include <iostream>
using namespace std;

void printEveryOther(int low, int high) {
    if (low > high) return;  // Base case
    cout << low << endl;
    printEveryOther(low + 2, high);
}
```

### Base Case

```
if (low > high) return;
```

### Explanation

The recursion stops when `low` becomes greater than `high`, preventing infinite recursion.

---

## 2. Modified Factorial Function

### Given Function

```
int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 2);
}
```

### What Happens When factorial(10) is Called?

The function computes:

```
10 * 8 * 6 * 4 * 2 * factorial(0)
```

After that:

```
factorial(0) → factorial(-2) → factorial(-4) → ...
```

### Final Answer

* There is no base case for `n == 0`
* The recursion continues indefinitely
* This results in infinite recursion and eventually a stack overflow error

---

## 3. Fixing the Missing Base Case

### Original Function

```
int sum(int low, int high) {
    return high + sum(low, high - 1);
}
```

### Fixed Function

```
int sum(int low, int high) {
    if (low == high) return low;  // Base case
    return high + sum(low, high - 1);
}
```

### Explanation

When `low == high`, recursion stops and returns the value.

---

## 4. Recursive Function to Print All Numbers in a Nested Structure

### Explanation

C++ does not support mixed-type nested arrays like scripting languages. To handle this, we use a recursive structure (`Node`) that can represent either a number or a list of other nodes.

### Code

```
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    bool isNumber;
    int value;
    vector<Node> children;

    Node(int val) {
        isNumber = true;
        value = val;
    }

    Node(vector<Node> elems) {
        isNumber = false;
        children = elems;
    }
};

void printNumbers(const Node& node) {
    if (node.isNumber) {
        cout << node.value << endl;
    } else {
        for (const auto& child : node.children) {
            printNumbers(child);
        }
    }
}

int main() {
    Node array = Node({
        Node(1), Node(2), Node(3),
        Node(vector<Node>{Node(4), Node(5), Node(6)}),
        Node(7),
        Node(vector<Node>{
            Node(8),
            Node(vector<Node>{
                Node(9), Node(10), Node(11),
                Node(vector<Node>{Node(12), Node(13), Node(14)})
            })
        }),
        Node(vector<Node>{
            Node(15), Node(16), Node(17), Node(18), Node(19),
            Node(vector<Node>{
                Node(20), Node(21), Node(22),
                Node(vector<Node>{
                    Node(23), Node(24), Node(25),
                    Node(vector<Node>{Node(26), Node(27), Node(29)})
                }),
                Node(30), Node(31)
            }),
            Node(32)
        }),
        Node(33)
    });

    printNumbers(array);
    return 0;
}
```

---

## Summary

* Base Case (Q1): low > high
* Factorial Issue (Q2): Infinite recursion → stack overflow
* Sum Fix (Q3): if (low == high) return low;
* Nested Structure (Q4): Recursive traversal using a custom Node structure
