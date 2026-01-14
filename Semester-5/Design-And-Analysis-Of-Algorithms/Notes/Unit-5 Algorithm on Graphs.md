# Unit 5: Algorithm on Graphs

## 📚 Syllabus Topics
- Depth First Search (DFS)
- Breadth First Search (BFS)
- DFS of a Directed Graph

---

## 1. Introduction to Graph Traversal

### 1.1 What is Graph Traversal?

**Graph traversal** means visiting all vertices and edges of a graph in a systematic way. It's a fundamental operation used in many graph algorithms.

### 1.2 Graph Representation

#### a) Adjacency Matrix
```
Graph:          Adjacency Matrix:
1 --- 2             1  2  3  4
|     |         1 [ 0  1  1  0 ]
|     |         2 [ 1  0  0  1 ]
3 --- 4         3 [ 1  0  0  1 ]
                4 [ 0  1  1  0 ]
```

**Space:** O(V²)
**Edge Check:** O(1)

#### b) Adjacency List
```
Graph:          Adjacency List:
1 --- 2         1 → [2, 3]
|     |         2 → [1, 4]
|     |         3 → [1, 4]
3 --- 4         4 → [2, 3]
```

**Space:** O(V + E)
**Edge Check:** O(degree)

### 1.3 Why Graph Traversal?

- **Finding path** between two vertices
- **Detecting cycles** in a graph
- **Connected components** detection
- **Topological sorting**
- **Finding strongly connected components**
- **Solving puzzles** (mazes, games)

---

## 2. Depth First Search (DFS)

### 2.1 Concept

DFS explores as far as possible along each branch before backtracking. It uses a **stack** (or recursion) to keep track of vertices.

**Strategy:** "Go deep, then backtrack"

### 2.2 Algorithm (Recursive)

```
Algorithm: DFS(G, v)
Input: Graph G, starting vertex v
Output: All vertices reachable from v are visited

1. Mark v as visited
2. Process/Print v
3. For each neighbor u of v:
      If u is not visited then
         DFS(G, u)
```

### 2.3 Algorithm (Iterative with Stack)

```
Algorithm: DFS_Iterative(G, start)
1. Create empty stack S
2. Push start onto S
3. While S is not empty:
      v = Pop from S
      If v is not visited then
         Mark v as visited
         Process/Print v
         For each neighbor u of v:
            If u is not visited then
               Push u onto S
```

### 2.4 Example

**Graph:**
```
        1
       /|\
      2 3 4
      |   |
      5   6
```

**Adjacency List:**
```
1 → [2, 3, 4]
2 → [1, 5]
3 → [1]
4 → [1, 6]
5 → [2]
6 → [4]
```

**DFS starting from 1:**
```
Visit 1 → Stack: [2, 3, 4] or explore 2
Visit 2 → Stack: [5]
Visit 5 → Stack: []
Backtrack to 2, then to 1
Visit 3 → Stack: []
Backtrack to 1
Visit 4 → Stack: [6]
Visit 6 → Stack: []

DFS Order: 1 → 2 → 5 → 3 → 4 → 6
```

### 2.5 C Implementation

```c
#define MAX 100
int visited[MAX];
int adj[MAX][MAX];  // Adjacency matrix
int n;              // Number of vertices

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int u = 0; u < n; u++) {
        if (adj[v][u] == 1 && !visited[u]) {
            DFS(u);
        }
    }
}

void DFS_All() {
    // Initialize all vertices as not visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Call DFS for unvisited vertices (handles disconnected graphs)
    for (int v = 0; v < n; v++) {
        if (!visited[v])
            DFS(v);
    }
}
```

### 2.6 Time and Space Complexity

| Representation | Time | Space |
|----------------|------|-------|
| **Adjacency Matrix** | O(V²) | O(V) |
| **Adjacency List** | O(V + E) | O(V) |

**Space O(V):** For visited array and recursion stack

---

## 3. Breadth First Search (BFS)

### 3.1 Concept

BFS explores all vertices at the current depth before moving to vertices at the next depth level. It uses a **queue** to keep track of vertices.

**Strategy:** "Explore level by level"

### 3.2 Algorithm

```
Algorithm: BFS(G, start)
Input: Graph G, starting vertex start
Output: All vertices reachable from start are visited

1. Create empty queue Q
2. Mark start as visited
3. Enqueue start into Q

4. While Q is not empty:
      v = Dequeue from Q
      Process/Print v

      For each neighbor u of v:
         If u is not visited then
            Mark u as visited
            Enqueue u into Q
```

### 3.3 Example

**Graph:**
```
        1
       /|\
      2 3 4
      |   |
      5   6
```

**BFS starting from 1:**
```
Level 0: Visit 1
         Queue: [2, 3, 4]

Level 1: Visit 2, 3, 4
         Queue: [5] (from 2), [6] (from 4)
         Queue: [5, 6]

Level 2: Visit 5, 6
         Queue: []

BFS Order: 1 → 2 → 3 → 4 → 5 → 6
```

### 3.4 C Implementation

```c
#define MAX 100
int visited[MAX];
int adj[MAX][MAX];
int n;

// Simple Queue implementation
int queue[MAX], front = 0, rear = -1;

void enqueue(int x) { queue[++rear] = x; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front > rear; }

void BFS(int start) {
    // Initialize
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    front = 0; rear = -1;

    // Start BFS
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int u = 0; u < n; u++) {
            if (adj[v][u] == 1 && !visited[u]) {
                visited[u] = 1;
                enqueue(u);
            }
        }
    }
}
```

### 3.5 BFS for Shortest Path (Unweighted)

BFS naturally finds the shortest path in an unweighted graph.

```c
int distance[MAX], parent[MAX];

void BFS_ShortestPath(int start) {
    for (int i = 0; i < n; i++) {
        distance[i] = -1;  // -1 means unreachable
        parent[i] = -1;
    }

    distance[start] = 0;
    enqueue(start);

    while (!isEmpty()) {
        int v = dequeue();

        for (int u = 0; u < n; u++) {
            if (adj[v][u] == 1 && distance[u] == -1) {
                distance[u] = distance[v] + 1;
                parent[u] = v;
                enqueue(u);
            }
        }
    }
}

void printPath(int dest) {
    if (parent[dest] != -1)
        printPath(parent[dest]);
    printf("%d ", dest);
}
```

### 3.6 Time and Space Complexity

| Representation | Time | Space |
|----------------|------|-------|
| **Adjacency Matrix** | O(V²) | O(V) |
| **Adjacency List** | O(V + E) | O(V) |

---

## 4. DFS vs BFS Comparison

| Feature | DFS | BFS |
|---------|-----|-----|
| **Data Structure** | Stack | Queue |
| **Strategy** | Deep first | Level by level |
| **Path Finding** | Any path | Shortest path (unweighted) |
| **Memory** | O(h) where h=height | O(w) where w=width |
| **Completeness** | May not find if infinite | Always finds |
| **Use Cases** | Cycle detection, Topological sort | Shortest path, Level order |

### Visual Comparison

```
Graph:
         A
        /|\
       B C D
      /|   |
     E F   G
       |
       H

DFS (from A): A → B → E → F → H → C → D → G
BFS (from A): A → B → C → D → E → F → G → H
```

---

## 5. DFS on Directed Graphs

### 5.1 Directed Graph Concepts

In a **directed graph (digraph)**, edges have direction. Edge (u, v) means there's an edge FROM u TO v.

```
Directed Graph:
1 → 2 → 4
↓   ↓
3 ← 5
```

### 5.2 Edge Classification in DFS

When performing DFS on a directed graph, edges are classified as:

| Edge Type | Description | Detection |
|-----------|-------------|-----------|
| **Tree Edge** | Part of DFS tree | First visit to vertex |
| **Back Edge** | To an ancestor | To a vertex on current path |
| **Forward Edge** | To a descendant (non-tree) | To a fully processed vertex with discover > current |
| **Cross Edge** | Between unrelated vertices | To a fully processed vertex with discover < current |

### 5.3 DFS with Timestamps

```
Algorithm: DFS_Directed(G, v)
Global: time = 0

1. time = time + 1
2. discover[v] = time      // Discovery time
3. color[v] = GRAY         // Currently being processed

4. For each neighbor u of v:
      If color[u] == WHITE then      // Tree edge
         parent[u] = v
         DFS_Directed(G, u)
      Else If color[u] == GRAY then  // Back edge (cycle!)
         Print "Back edge found: cycle detected"
      Else                           // Forward or Cross edge
         If discover[v] < discover[u] then
            Print "Forward edge"
         Else
            Print "Cross edge"

5. color[v] = BLACK        // Fully processed
6. time = time + 1
7. finish[v] = time        // Finish time
```

### 5.4 Colors in DFS

| Color | Meaning |
|-------|---------|
| **WHITE** | Not yet discovered |
| **GRAY** | Discovered but not finished (on current path) |
| **BLACK** | Completely processed |

### 5.5 Cycle Detection in Directed Graph

A directed graph has a cycle if and only if there's a **back edge** during DFS.

```c
#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[MAX];
int hasCycle = 0;

void DFS_Cycle(int v) {
    color[v] = GRAY;

    for (int u = 0; u < n; u++) {
        if (adj[v][u]) {
            if (color[u] == GRAY) {
                // Back edge found - cycle exists!
                hasCycle = 1;
                return;
            }
            if (color[u] == WHITE) {
                DFS_Cycle(u);
            }
        }
    }

    color[v] = BLACK;
}

int detectCycle() {
    for (int i = 0; i < n; i++)
        color[i] = WHITE;
    hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (color[i] == WHITE)
            DFS_Cycle(i);
    }
    return hasCycle;
}
```

### 5.6 Example: DFS on Directed Graph

```
Directed Graph:
    1 → 2
    ↓   ↓
    3 → 4
    ↑___|  (4 → 3 creates cycle)
```

**DFS from 1 with timestamps:**
```
Start DFS(1): discover[1] = 1, color[1] = GRAY
  → DFS(2): discover[2] = 2, color[2] = GRAY
      → DFS(4): discover[4] = 3, color[4] = GRAY
          → Check 3: color[3] = WHITE
          → DFS(3): discover[3] = 4, color[3] = GRAY
              → Check 4: color[4] = GRAY → BACK EDGE (Cycle!)
          finish[3] = 5, color[3] = BLACK
      finish[4] = 6, color[4] = BLACK
  finish[2] = 7, color[2] = BLACK
  → DFS(3): Already BLACK, skip
finish[1] = 8, color[1] = BLACK
```

---

## 6. Applications of DFS and BFS

### 6.1 DFS Applications

| Application | How DFS Helps |
|-------------|---------------|
| **Cycle Detection** | Back edges indicate cycles |
| **Topological Sorting** | Reverse of finish times |
| **Strongly Connected Components** | Kosaraju's or Tarjan's algorithm |
| **Path Finding** | Explores all paths |
| **Maze Solving** | Deep exploration |
| **Finding Bridges** | Uses discovery times |
| **Finding Articulation Points** | Uses discovery times |

### 6.2 BFS Applications

| Application | How BFS Helps |
|-------------|---------------|
| **Shortest Path (Unweighted)** | Level-by-level guarantees shortest |
| **Level Order Traversal** | Natural level-by-level exploration |
| **Connected Components** | Visit all nodes in component |
| **Bipartite Check** | Two-coloring using levels |
| **Minimum Spanning Tree (Unweighted)** | All edges have same weight |
| **Web Crawlers** | Explore pages by link depth |
| **Social Networks** | Finding friends at k distance |

---

## 7. Topological Sorting (Using DFS)

### 7.1 Definition

**Topological Sort** is a linear ordering of vertices in a **DAG (Directed Acyclic Graph)** such that for every directed edge (u, v), u comes before v.

### 7.2 Algorithm Using DFS

```
Algorithm: TopologicalSort(G)
1. Call DFS to compute finish times for all vertices
2. As each vertex finishes, add it to front of a list
3. Return the list

DFS_Topo(v):
1. Mark v as visited
2. For each neighbor u of v:
      If u is not visited then
         DFS_Topo(u)
3. Add v to front of result list (or push to stack)
```

### 7.3 Example

```
Graph (Dependencies):
5 → 0 ← 4
↓       ↓
2 → 3 → 1
```

**DFS finish order (reverse):**
- Possible topological order: 5, 4, 2, 3, 1, 0
- Another valid order: 4, 5, 2, 3, 1, 0

---

## 8. Summary Table

| Algorithm | Data Structure | Time | Space | Finds Shortest Path? |
|-----------|----------------|------|-------|---------------------|
| **DFS** | Stack/Recursion | O(V+E) | O(V) | No |
| **BFS** | Queue | O(V+E) | O(V) | Yes (unweighted) |

---

## 📝 Important Questions

1. Explain DFS algorithm with an example. Write its time complexity.
2. Explain BFS algorithm with an example. How is it different from DFS?
3. How does BFS find the shortest path in an unweighted graph?
4. Classify edges in DFS of a directed graph. Explain each type.
5. How can you detect a cycle in a directed graph using DFS?
6. Perform DFS and BFS on the following graph starting from vertex A: [with diagram]
7. What is topological sorting? Explain with an algorithm.
8. Compare DFS and BFS in terms of data structure, applications, and complexity.
9. Explain the color coding (WHITE, GRAY, BLACK) used in DFS of directed graphs.

---

## 📖 References
- Horowitz E - Computer Algorithms, Galgotia Publication
- Aho A.V, Hopcroft J.E & Ullman J.D - The Design and Analysis of Computer Algorithm, Addison Wesley
