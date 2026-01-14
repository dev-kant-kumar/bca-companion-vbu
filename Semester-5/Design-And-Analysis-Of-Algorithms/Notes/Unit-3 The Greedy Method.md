# Unit 3: The Greedy Method

## 📚 Syllabus Topics
- The General Method
- Minimum Cost Spanning Trees
  - Kruskal's Algorithm
  - Prim's Algorithm

---

## 1. The Greedy Method

### 1.1 What is Greedy Method?

The **Greedy Method** is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit (locally optimal choice), hoping it leads to a globally optimal solution.

### 1.2 Key Characteristics

| Characteristic | Description |
|----------------|-------------|
| **Greedy Choice Property** | A global optimum can be reached by choosing local optimum |
| **Optimal Substructure** | An optimal solution contains optimal solutions to sub-problems |
| **No Backtracking** | Once a choice is made, it is never reconsidered |
| **Efficiency** | Generally faster than dynamic programming |

### 1.3 General Greedy Algorithm

```
Algorithm: Greedy(A, n)
Input: Set A of n elements
Output: Solution set S

1. S = ∅  (Initialize solution as empty)
2. For i = 1 to n do
      x = Select(A)          // Select best candidate
      If Feasible(S, x) then // Check if adding x is valid
         S = S ∪ {x}         // Add x to solution
3. Return S
```

### 1.4 Components of Greedy Algorithm

1. **Candidate Set:** Set of possible choices
2. **Selection Function:** Chooses the best candidate
3. **Feasibility Function:** Checks if candidate can contribute to solution
4. **Objective Function:** Assigns value to a solution (to be maximized/minimized)
5. **Solution Function:** Checks if we have found a complete solution

### 1.5 When Does Greedy Work?

| Works Well | May Not Work |
|------------|--------------|
| Fractional Knapsack | 0/1 Knapsack |
| Activity Selection | Some scheduling problems |
| Huffman Coding | Shortest Path (with negative edges) |
| Minimum Spanning Tree | Traveling Salesman |

### 1.6 Greedy vs Dynamic Programming

| Greedy | Dynamic Programming |
|--------|---------------------|
| Makes locally optimal choice | Considers all possibilities |
| No overlapping sub-problems | Has overlapping sub-problems |
| Faster (usually O(n) or O(n log n)) | Slower (usually O(n²) or more) |
| May not give optimal solution | Always gives optimal solution |
| Top-down approach | Bottom-up or top-down with memoization |

---

## 2. Minimum Cost Spanning Tree (MST)

### 2.1 Definitions

**Graph:** G = (V, E) where V is set of vertices and E is set of edges

**Spanning Tree:** A tree that includes all vertices of the graph with minimum edges (n-1 edges for n vertices)

**Minimum Cost Spanning Tree:** A spanning tree where the sum of edge weights is minimum

### 2.2 Properties of Spanning Tree

- Contains all vertices (n vertices)
- Has exactly (n-1) edges
- No cycles
- Connected (path between every pair of vertices)
- Removing any edge disconnects the graph
- Adding any edge creates a cycle

### 2.3 Example Graph

```
        10
    1 ─────── 2
    │\        │\
   6│  \15   5│  \12
    │    \    │    \
    3 ────── 4 ───── 5
        8        9
```

This graph can have multiple spanning trees. MST is the one with minimum total weight.

---

## 3. Kruskal's Algorithm

### 3.1 Strategy

1. Sort all edges in ascending order of their weight
2. Pick the smallest edge that doesn't form a cycle
3. Repeat until we have (n-1) edges

### 3.2 Algorithm

```
Algorithm: Kruskal(G)
Input: Graph G = (V, E) with weights
Output: Minimum Spanning Tree T

1. T = ∅                              // Initialize MST as empty
2. Sort all edges E by weight (ascending)
3. Create disjoint sets for each vertex

4. For each edge (u, v) in sorted order:
      If Find(u) ≠ Find(v) then       // u and v are in different sets
         T = T ∪ {(u, v)}             // Add edge to MST
         Union(u, v)                   // Merge the sets
      If |T| == |V| - 1 then
         Break                         // MST complete

5. Return T
```

### 3.3 Disjoint Set Operations

```
// Initialize: Each vertex is its own set
MakeSet(x):
    parent[x] = x
    rank[x] = 0

// Find the root/representative of set containing x
Find(x):
    If parent[x] ≠ x then
        parent[x] = Find(parent[x])  // Path compression
    Return parent[x]

// Union two sets
Union(x, y):
    rootX = Find(x)
    rootY = Find(y)

    If rank[rootX] < rank[rootY] then
        parent[rootX] = rootY
    Else If rank[rootX] > rank[rootY] then
        parent[rootY] = rootX
    Else
        parent[rootY] = rootX
        rank[rootX] = rank[rootX] + 1
```

### 3.4 Example

**Graph:**
```
        1
    A ─────── B
    │\        │
   3│  \4    2│
    │    \    │
    C ─────── D
        5
```

**Edges sorted:** (A,B,1), (B,D,2), (A,C,3), (A,D,4), (C,D,5)

| Step | Edge | Weight | Action | MST |
|------|------|--------|--------|-----|
| 1 | (A,B) | 1 | A,B in different sets → Add | {(A,B)} |
| 2 | (B,D) | 2 | B,D in different sets → Add | {(A,B), (B,D)} |
| 3 | (A,C) | 3 | A,C in different sets → Add | {(A,B), (B,D), (A,C)} |
| 4 | (A,D) | 4 | A,D in same set → **Skip** (would form cycle) | - |
| **Done!** | | | 3 edges for 4 vertices | |

**MST:**
```
        1
    A ─────── B
    │         │
   3│        2│
    │         │
    C         D

Total Weight = 1 + 2 + 3 = 6
```

### 3.5 Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Sorting edges | O(E log E) |
| Union-Find operations | O(E × α(V)) ≈ O(E) |
| **Total** | **O(E log E)** or **O(E log V)** |

*Note: α is the inverse Ackermann function, practically constant*

---

## 4. Prim's Algorithm

### 4.1 Strategy

1. Start from any vertex
2. Grow the tree by adding the minimum weight edge connecting a vertex in the tree to a vertex outside
3. Repeat until all vertices are included

### 4.2 Algorithm

```
Algorithm: Prim(G, start)
Input: Graph G = (V, E) with weights, starting vertex
Output: Minimum Spanning Tree T

1. Initialize:
   - key[v] = ∞ for all v         // Minimum weight to connect v
   - key[start] = 0                // Start vertex has key 0
   - parent[v] = NULL for all v
   - inMST[v] = false for all v

2. While there are vertices not in MST:
      u = vertex with minimum key not in MST
      inMST[u] = true              // Add u to MST

      For each neighbor v of u:
         If not inMST[v] AND weight(u,v) < key[v] then
            key[v] = weight(u,v)
            parent[v] = u

3. T = {(parent[v], v) for all v ≠ start}
4. Return T
```

### 4.3 Example

**Graph:**
```
        1
    A ─────── B
    │\        │
   3│  \4    2│
    │    \    │
    C ─────── D
        5
```

**Starting from A:**

| Step | Current | key[A] | key[B] | key[C] | key[D] | inMST | MST Edges |
|------|---------|--------|--------|--------|--------|-------|-----------|
| Init | - | 0 | ∞ | ∞ | ∞ | {} | {} |
| 1 | A | **0** | 1 | 3 | 4 | {A} | {} |
| 2 | B | - | **1** | 3 | 2 | {A,B} | {(A,B)} |
| 3 | D | - | - | 3 | **2** | {A,B,D} | {(A,B), (B,D)} |
| 4 | C | - | - | **3** | - | {A,B,D,C} | {(A,B), (B,D), (A,C)} |

**MST:**
```
        1
    A ─────── B
    │         │
   3│        2│
    │         │
    C         D

Total Weight = 1 + 2 + 3 = 6
```

### 4.4 Implementation Using Priority Queue

```c
// Using adjacency list and min-heap
void primMST(int graph[][], int n) {
    int key[n], parent[n];
    bool inMST[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        // Get minimum key vertex not in MST
        int u = minKey(key, inMST, n);
        inMST[u] = true;

        // Update keys of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    for (int i = 1; i < n; i++)
        printf("%d - %d: %d\n", parent[i], i, graph[i][parent[i]]);
}
```

### 4.5 Complexity Analysis

| Implementation | Time Complexity |
|----------------|-----------------|
| Adjacency Matrix + Array | O(V²) |
| Adjacency List + Binary Heap | O((V + E) log V) = O(E log V) |
| Adjacency List + Fibonacci Heap | O(E + V log V) |

---

## 5. Comparison: Kruskal's vs Prim's Algorithm

| Feature | Kruskal's | Prim's |
|---------|-----------|--------|
| **Approach** | Edge-based | Vertex-based |
| **Strategy** | Sort edges, pick smallest | Grow from a vertex |
| **Data Structure** | Union-Find | Priority Queue |
| **Complexity** | O(E log E) | O(E log V) with heap |
| **Best For** | Sparse graphs | Dense graphs |
| **Starting Point** | No starting vertex needed | Needs starting vertex |
| **Graph Type** | Works on disconnected (finds forest) | Works on connected only |

---

## 6. Proof of Correctness

### 6.1 Cut Property

**Theorem:** For any cut in the graph, the minimum weight edge crossing the cut belongs to some MST.

**Proof Sketch:**
- Let (u, v) be the minimum weight edge crossing a cut
- Suppose T is an MST that doesn't contain (u, v)
- T must have some edge (x, y) crossing the same cut
- Replace (x, y) with (u, v): new tree T' has weight ≤ T
- Since T is MST, T' = T (contradiction if weight < T)

### 6.2 Why Greedy Works for MST?

1. **Greedy Choice:** At each step, we choose the minimum weight edge
2. **Safe Edge:** The edge we add doesn't create a cycle
3. **Cut Property:** Guarantees this edge is part of some MST
4. **Optimal Substructure:** MST of sub-graph is part of MST of full graph

---

## 7. Applications of MST

1. **Network Design**
   - Laying cables (phone, electrical, fiber optic)
   - Pipeline networks
   - Road networks

2. **Cluster Analysis**
   - Remove the k-1 most expensive edges to get k clusters

3. **Image Processing**
   - Image segmentation

4. **Approximation Algorithms**
   - Used in TSP approximation (2-approximation)

---

## 8. Summary Table

| Concept | Key Points |
|---------|------------|
| **Greedy Method** | Make locally optimal choices hoping for global optimum |
| **MST** | Tree connecting all vertices with minimum total weight |
| **Kruskal's** | Sort edges, add smallest that doesn't form cycle |
| **Prim's** | Start from vertex, grow tree by adding minimum edge |
| **Correctness** | Guaranteed by Cut Property |

---

## 📝 Important Questions

1. Explain the Greedy Method with its characteristics.
2. What is Minimum Cost Spanning Tree? List its properties.
3. Explain Kruskal's algorithm with an example. What is its time complexity?
4. Explain Prim's algorithm with an example. Compare it with Kruskal's.
5. Prove that Kruskal's algorithm gives the minimum cost spanning tree.
6. What is the Cut Property? How does it guarantee correctness of MST algorithms?
7. Apply Kruskal's and Prim's algorithm on the following graph: [with diagram]
8. Compare Kruskal's and Prim's algorithm.

---

## 📖 References
- Horowitz E - Computer Algorithms, Galgotia Publication
- Aho A.V, Hopcroft J.E & Ullman J.D - The Design and Analysis of Computer Algorithm, Addison Wesley
