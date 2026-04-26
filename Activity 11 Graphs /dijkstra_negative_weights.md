1. Overview of Dijkstra’s Algorithm

Dijkstra’s algorithm is used to find the shortest path from a source node to all other nodes in a graph with non-negative edge weights.

Key Idea:
Always pick the node with the smallest known distance
Once a node is “finalized,” its shortest distance is assumed correct

This assumption is the core reason it fails with negative weights.

2. Example Graph with Negative Weight

Consider the following directed graph:
A → B (cost = 4)
A → C (cost = 1)
C → B (cost = -3)
Visual Representation:
     (4)
  A -----> B
   \       
    \      
    (1)    
      \    
       v   
        C
        |
       (-3)
        |
        v
        B
3. Applying Dijkstra’s Algorithm
Step 1: Initialize distances
A = 0 (source)
B = ∞
C = ∞ 
Step 2: Visit A
Update neighbors:
B = 4
C = 1
Step 3: Pick smallest distance → C (1)
From C → B:
New distance to B = 1 + (-3) = -2
Update B = -2
Step 4: 
Pick smallest distance → B (-2) 
At this point, things seem correct. 
But here’s the issue:
If the algorithm had picked B earlier (which can happen in 
slightly different graphs), it would have finalized B too early and missed the better path through C.
4. Why Dijkstra’s Algorithm Fails

Dijkstra’s algorithm assumes:

Once the shortest path to a node is found, it will never change.

This assumption is only valid when all edge weights are non-negative.

Problem with Negative Weights:
A shorter path can appear later
Previously finalized nodes may actually have better paths discovered afterward
Key Insight:
Dijkstra is greedy
Negative weights break the greedy assumption
5. Simple Failure Scenario (Conceptual)

Imagine:

You reach node B with cost 4
You mark it as “done”
Later, you find a path with cost -2

Too late — Dijkstra already finalized B and won’t update it\
6. Correct Algorithm for Negative Weights

When negative weights exist, use:

Bellman-Ford Algorithm
Handles negative weights
Detects negative cycles
Time complexity: O(V × E)
7. Conclusion

Dijkstra’s algorithm fails on graphs with negative weights because it:

Finalizes nodes too early
Assumes no shorter path will appear later

This assumption breaks when negative edges allow distances to decrease after a node has already been processed.
