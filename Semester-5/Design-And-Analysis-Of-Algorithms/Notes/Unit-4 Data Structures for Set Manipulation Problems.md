# Unit 4: Data Structures for Set Manipulation Problems

## 📚 Syllabus Topics
- Fundamental Operations on Set
- Hashing Technique
- Binary Search Trees

---

## 1. Fundamental Operations on Set

### 1.1 What is a Set?

A **Set** is a collection of distinct elements. In computer science, sets are fundamental data structures used to store unique elements.

### 1.2 Basic Set Operations

| Operation | Symbol | Description |
|-----------|--------|-------------|
| **Union** | A ∪ B | All elements in A or B or both |
| **Intersection** | A ∩ B | Elements common to both A and B |
| **Difference** | A - B | Elements in A but not in B |
| **Complement** | A' | Elements not in A |
| **Symmetric Difference** | A △ B | Elements in A or B but not both |

### 1.3 Set ADT Operations

```
ADT Set:
    Create()         - Create empty set
    MakeSet(x)       - Create set containing only x
    Insert(S, x)     - Add element x to set S
    Delete(S, x)     - Remove element x from set S
    Member(S, x)     - Check if x is in set S
    Minimum(S)       - Return smallest element in S
    Maximum(S)       - Return largest element in S
    Union(S1, S2)    - Return S1 ∪ S2
    Find(x)          - Find set containing x
```

### 1.4 Set Representations

| Representation | Insert | Delete | Member | Union |
|----------------|--------|--------|--------|-------|
| **Bit Vector** | O(1) | O(1) | O(1) | O(n) |
| **Linked List** | O(1) | O(n) | O(n) | O(m×n) |
| **Sorted Array** | O(n) | O(n) | O(log n) | O(m+n) |
| **BST** | O(log n) | O(log n) | O(log n) | O(m+n) |
| **Hash Table** | O(1) avg | O(1) avg | O(1) avg | O(m+n) |

### 1.5 Disjoint Set (Union-Find)

**Disjoint Sets** are sets with no common elements. Used in Kruskal's algorithm.

```
Operations:
- MakeSet(x): Create a new set containing only x
- Find(x): Return the representative of set containing x
- Union(x, y): Merge sets containing x and y
```

#### Implementation with Path Compression and Union by Rank

```c
int parent[MAX], rank[MAX];

void makeSet(int x) {
    parent[x] = x;
    rank[x] = 0;
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);  // Path compression
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) return;

    // Union by rank
    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}
```

**Time Complexity:** Nearly O(1) per operation (amortized)

---

## 2. Hashing Technique

### 2.1 What is Hashing?

**Hashing** is a technique to map data of arbitrary size to fixed-size values using a **hash function**. It enables O(1) average-case access.

### 2.2 Components

1. **Hash Table:** Array that stores elements
2. **Hash Function:** Maps keys to array indices
3. **Collision Resolution:** Handles when two keys hash to same index

### 2.3 Hash Function

**Properties of a Good Hash Function:**
- **Deterministic:** Same key always produces same hash
- **Uniform Distribution:** Keys distributed evenly across table
- **Fast to compute:** O(1) time
- **Minimizes collisions**

### 2.4 Common Hash Functions

#### a) Division Method
```
h(k) = k mod m

where m = table size (preferably prime)
```

**Example:** k = 123, m = 10
- h(123) = 123 mod 10 = 3

#### b) Multiplication Method
```
h(k) = ⌊m × (k × A mod 1)⌋

where A ≈ 0.6180339887 (golden ratio - 1)
```

#### c) Mid-Square Method
```
1. Square the key
2. Extract middle digits
```

**Example:** k = 4321
- k² = 18,671,041
- Middle two digits: 71
- h(4321) = 71

#### d) Folding Method
```
1. Divide key into equal-sized parts
2. Add the parts
```

**Example:** k = 12345678, fold into pairs
- 12 + 34 + 56 + 78 = 180
- h(k) = 180 (or 180 mod m)

### 2.5 Collision Resolution Techniques

#### a) Separate Chaining (Open Hashing)

Store colliding elements in a linked list at each slot.

```
Hash Table:
Index | Elements
  0   | → 10 → 20 → 30
  1   | → 11
  2   | → NULL
  3   | → 13 → 23
  ...
```

```c
// Structure
struct Node {
    int key;
    struct Node* next;
};

struct Node* hashTable[SIZE];

void insert(int key) {
    int index = key % SIZE;
    struct Node* newNode = createNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

bool search(int key) {
    int index = key % SIZE;
    struct Node* current = hashTable[index];
    while (current != NULL) {
        if (current->key == key) return true;
        current = current->next;
    }
    return false;
}
```

**Complexity:**
- Average: O(1 + α) where α = n/m (load factor)
- Worst: O(n) when all keys hash to same slot

---

#### b) Open Addressing (Closed Hashing)

All elements stored in the hash table itself. On collision, probe for next empty slot.

**Probing Techniques:**

##### i) Linear Probing
```
h(k, i) = (h(k) + i) mod m

where i = 0, 1, 2, 3, ...
```

**Example:** Insert 23, 43, 13 into table of size 10
- h(23) = 23 mod 10 = 3 → Insert at 3
- h(43) = 43 mod 10 = 3 → Collision! Try 4 → Insert at 4
- h(13) = 13 mod 10 = 3 → Collision! Try 4 → Collision! Try 5 → Insert at 5

```
Index: 0  1  2  3   4   5  6  7  8  9
Value: -  -  -  23  43  13 -  -  -  -
```

**Problem:** Primary Clustering (consecutive filled slots)

---

##### ii) Quadratic Probing
```
h(k, i) = (h(k) + c₁×i + c₂×i²) mod m

Commonly: h(k, i) = (h(k) + i²) mod m
```

**Example:** Insert 23, 43, 13 (m=10)
- h(23, 0) = 3 → Insert at 3
- h(43, 0) = 3 → Collision! h(43, 1) = 3 + 1 = 4 → Insert at 4
- h(13, 0) = 3 → Collision! h(13, 1) = 4 → Collision! h(13, 2) = 3 + 4 = 7 → Insert at 7

**Problem:** Secondary Clustering (less severe)

---

##### iii) Double Hashing
```
h(k, i) = (h₁(k) + i × h₂(k)) mod m

Common choices:
h₁(k) = k mod m
h₂(k) = 1 + (k mod (m-1))
```

**Example:** Insert 23, 43 (m=10)
- h₁(23) = 3, h₂(23) = 1 + (23 mod 9) = 6
- h(23, 0) = 3 → Insert at 3
- h₁(43) = 3, h₂(43) = 1 + (43 mod 9) = 8
- h(43, 0) = 3 → Collision! h(43, 1) = (3 + 8) mod 10 = 1 → Insert at 1

**Best:** Eliminates clustering

### 2.6 Comparison of Collision Resolution

| Technique | Clustering | Memory | Cache | Deletion |
|-----------|------------|--------|-------|----------|
| **Chaining** | None | Extra (pointers) | Poor | Easy |
| **Linear Probing** | Primary | No extra | Good | Difficult |
| **Quadratic Probing** | Secondary | No extra | Fair | Difficult |
| **Double Hashing** | None | No extra | Fair | Difficult |

### 2.7 Load Factor

**Load Factor (α)** = Number of elements / Table size = n/m

| α Range | Performance |
|---------|-------------|
| α < 0.5 | Excellent |
| 0.5 ≤ α < 0.7 | Good |
| 0.7 ≤ α < 0.9 | Fair |
| α ≥ 0.9 | Poor (rehash needed) |

### 2.8 Rehashing

When load factor exceeds threshold:
1. Create new table (usually 2× size)
2. Recompute hash for all elements
3. Insert into new table

---

## 3. Binary Search Trees (BST)

### 3.1 Definition

A **Binary Search Tree** is a binary tree where:
- Left subtree contains nodes with keys **less than** the root
- Right subtree contains nodes with keys **greater than** the root
- Both subtrees are also BSTs

### 3.2 BST Property

```
For any node X:
   All keys in LEFT subtree < X.key < All keys in RIGHT subtree
```

### 3.3 Example

```
           50
         /    \
       30      70
      /  \    /  \
    20   40  60   80
```

In-order traversal gives sorted sequence: 20, 30, 40, 50, 60, 70, 80

### 3.4 BST Node Structure

```c
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
```

### 3.5 BST Operations

#### a) Search

```c
struct Node* search(struct Node* root, int key) {
    // Base cases: root is null or key is at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (key > root->key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}
```

**Time Complexity:** O(h) where h = height of tree

---

#### b) Insert

```c
struct Node* insert(struct Node* root, int key) {
    // Tree is empty, return new node
    if (root == NULL)
        return createNode(key);

    // Otherwise, recur down the tree
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    // Return unchanged node pointer
    return root;
}
```

**Example:** Insert 35 into above tree
```
           50
         /    \
       30      70
      /  \    /  \
    20   40  60   80
        /
      35  ← New node
```

---

#### c) Delete

Three cases:
1. **Leaf node:** Simply remove
2. **One child:** Replace with child
3. **Two children:** Replace with in-order successor (or predecessor)

```c
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    // Find the node to delete
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node found, handle deletion

        // Case 1 & 2: Node with 0 or 1 child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
```

**Example:** Delete 30 from tree
```
Before:             After:
       50                 50
      /   \             /    \
    30     70    →    35      70
   /  \   /  \       /       /  \
  20  40 60  80    20  40   60   80
     /
   35
```

---

#### d) Traversals

```c
// In-order: Left, Root, Right (gives sorted order)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Pre-order: Root, Left, Right
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order: Left, Right, Root
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}
```

---

#### e) Find Minimum and Maximum

```c
// Minimum: Leftmost node
struct Node* findMin(struct Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Maximum: Rightmost node
struct Node* findMax(struct Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}
```

### 3.6 Complexity Analysis

| Operation | Average Case | Worst Case |
|-----------|-------------|------------|
| **Search** | O(log n) | O(n) |
| **Insert** | O(log n) | O(n) |
| **Delete** | O(log n) | O(n) |
| **Min/Max** | O(log n) | O(n) |

**Worst case** occurs when tree becomes a linked list (skewed tree)

### 3.7 Balanced vs Unbalanced BST

```
Balanced:           Unbalanced (Skewed):
       4                  1
      / \                  \
     2   6                  2
    / \ / \                  \
   1  3 5  7                  3
                               \
                                4
Height = O(log n)      Height = O(n)
```

### 3.8 Self-Balancing BSTs

To maintain O(log n) operations:
- **AVL Trees:** Strict balance (height difference ≤ 1)
- **Red-Black Trees:** Relaxed balance (used in STL)
- **B-Trees:** Multiple keys per node (used in databases)

---

## 4. Summary Table

| Data Structure | Search | Insert | Delete | Space |
|----------------|--------|--------|--------|-------|
| **Hash Table** | O(1) avg | O(1) avg | O(1) avg | O(n) |
| **BST** | O(log n) avg | O(log n) avg | O(log n) avg | O(n) |
| **Sorted Array** | O(log n) | O(n) | O(n) | O(n) |
| **Unsorted Array** | O(n) | O(1) | O(n) | O(n) |

---

## 📝 Important Questions

1. What are the fundamental operations on sets? Explain with examples.
2. Explain hashing and its components. What makes a good hash function?
3. What is collision in hashing? Explain different collision resolution techniques.
4. Compare separate chaining and open addressing.
5. Explain linear probing with an example. What is primary clustering?
6. Define Binary Search Tree. Write algorithms for search, insert, and delete.
7. Perform insertion of 50, 30, 70, 20, 40, 60, 80 into an empty BST and show the tree.
8. Delete node 30 from a BST having two children. Explain the process.
9. Compare BST and Hash Table for set operations.

---

## 📖 References
- Horowitz E - Computer Algorithms, Galgotia Publication
- Aho A.V, Hopcroft J.E & Ullman J.D - The Design and Analysis of Computer Algorithm, Addison Wesley
