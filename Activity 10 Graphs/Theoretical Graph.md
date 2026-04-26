      A
     / \
    B   C
   / \   \
  D   E   F

Adjacency List Representation:
A → B, C
B → A, D, E
C → A, F
D → B
E → B
F → C

3. Time Complexity Comparison
Breadth-First Search (BFS)
Uses a queue
Visits each vertex and edge once
Time Complexity: O(V + E)
Depth-First Search (DFS)
Uses recursion (or stack)
Also visits each vertex and edge once
Time Complexity: O(V + E)
