# Space Constraints — Programming Assignment

---

## Task 1: Space Complexity of `wordBuilder`

```javascript
function wordBuilder(array) {
    let collection = [];
    for (let i = 0; i < array.length; i++) {
        for (let j = 0; j < array.length; j++) {
            if (i !== j) {
                collection.push(array[i] + array[j]);
            }
        }
    }
    return collection;
}
```

### Analysis

The function builds every possible two-character combination from the input array (excluding same-index pairs). For an input array of size **N**, the outer loop runs N times and the inner loop runs N times, generating approximately **N² string pairs** stored in `collection`.

- The `collection` array grows with every valid pair pushed into it.
- For N elements, there are N × (N − 1) pairs (every i/j combination where i ≠ j).
- Each stored string is a constant-length two-character concatenation, so each entry is O(1) space.

**Space Complexity: O(N²)**

The dominant space cost is the `collection` array which holds roughly N² items, so the space usage grows quadratically with the size of the input.

---

## Task 2: Space Complexity of `reverse`

```javascript
function reverse(array) {
    let newArray = [];
    for (let i = array.length - 1; i >= 0; i--) {
        newArray.push(array[i]);
    }
    return newArray;
}
```

### Analysis

This function creates a brand-new array (`newArray`) and copies every element from the input into it in reverse order. If the input has **N** elements, the new array also holds exactly **N** elements.

- The additional memory used scales directly with the size of the input.
- No other data structures are created; only one extra array of size N exists.

**Space Complexity: O(N)**

The function uses linear extra space because it allocates a new array the same size as the input.

---

## Task 3: In-Place Reverse Using O(1) Extra Space

To reverse an array using only **O(1)** extra space, we swap elements from both ends moving toward the center — no new array is needed. Only a single temporary variable is used regardless of input size.

```javascript
function reverseInPlace(array) {
    let left = 0;
    let right = array.length - 1;

    while (left < right) {
        // Swap elements at left and right pointers
        let temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }

    return array;
}
```

### Explanation

- `left` and `right` are two pointer variables — constant space regardless of array size.
- `temp` holds one element at a time during the swap — also constant space.
- The array itself is modified **in place**; no new array is allocated.
- Total extra memory used: 3 variables (`left`, `right`, `temp`) → **O(1)** space.

**Space Complexity: O(1)**

---

## Task 4: Comparing Three `doubleArray` Implementations

### The Three Versions

```javascript
// Version 1 — creates a new array
function doubleArray1(array) {
    let newArray = [];
    for (let i = 0; i < array.length; i++) {
        newArray.push(array[i] * 2);
    }
    return newArray;
}

// Version 2 — modifies array in place
function doubleArray2(array) {
    for (let i = 0; i < array.length; i++) {
        array[i] *= 2;
    }
    return array;
}

// Version 3 — recursive in-place modification
function doubleArray3(array, index = 0) {
    if (index >= array.length) { return; }
    array[index] *= 2;
    doubleArray3(array, index + 1);
    return array;
}
```

### Complexity Table

| Version   | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Version 1 | O(N)            | O(N)             |
| Version 2 | O(N)            | O(1)             |
| Version 3 | O(N)            | O(N)             |

### Detailed Explanations

#### Version 1 — O(N) time, O(N) space
- Iterates through every element once → **O(N) time**.
- Allocates a new array `newArray` with N elements → **O(N) space**.
- The original array is untouched; a full copy is returned.

#### Version 2 — O(N) time, O(1) space
- Iterates through every element once → **O(N) time**.
- Modifies the input array directly; no new data structure is created.
- Only the loop counter `i` is extra memory, which is constant → **O(1) space**.
- This is the most memory-efficient version.

#### Version 3 — O(N) time, O(N) space
- Makes one recursive call per element → **O(N) time**.
- Each recursive call adds a new **stack frame** to the call stack. With N elements, there are N nested calls on the stack simultaneously at peak depth.
- Even though no new array is allocated, the call stack itself consumes O(N) memory → **O(N) space**.
- Despite modifying in place, the recursion depth makes this equivalent to Version 1 in space usage.

### Key Insight
Version 2 is the clear winner for space efficiency. Version 3 looks similar to Version 2 (both modify the array in place), but the hidden cost of recursive call stack frames brings its space complexity back up to O(N).
