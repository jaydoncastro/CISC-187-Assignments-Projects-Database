1. Insert 11 into the heap
Step 1: Place 11 at the next available spot (bottom, left-to-right)

It goes under node 5 (as its right child).

Step 2: Heapify up
11 > 5 → swap
11 > 9 → swap
11 > 10 → swap

Final heap after insertion:
        11
       /  \
     10    8
    / \   / \
   6   9 7   4
  / \  /
 2  1 5
      \
       3

       
2. Delete the root (from the new heap)
Step 1: Replace root (11) with last element (3)
Step 2: Heapify down
3 < 10 → swap
3 < 9 → swap
3 < 5 → swap

Final heap after deletion:
        10
       /  \
      9    8
     / \   / \
    6   5 7   4
   / \  /
  2  1 3


  3. Insert sequence: 55, 22, 34, 10, 2, 99, 68
We build a max heap, then repeatedly pop (remove max).

Final sorted order after popping:
99, 68, 55, 34, 22, 10, 2

Key idea
A max heap always gives you the largest element first when popping, so it behaves like a descending sort.
In a max heap, we insert at the next available position to maintain completeness.
We then heapify up by swapping with the parent until the heap property is restored.
