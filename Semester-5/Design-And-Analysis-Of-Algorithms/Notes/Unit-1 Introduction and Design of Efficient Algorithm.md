# Unit 1: Introduction & Design of Efficient Algorithm

## 📚 Syllabus Topics
- Algorithm
- Complexity
- Asymptotic Notations
- Solving Recurrences

---

## 1. Algorithm

### 1.1 Definition
An **algorithm** is a finite set of well-defined instructions or step-by-step procedures to solve a specific problem or perform a computation.

### 1.2 Characteristics of an Algorithm

| Characteristic | Description |
|----------------|-------------|
| **Input** | Zero or more quantities are externally supplied |
| **Output** | At least one quantity is produced |
| **Definiteness** | Each instruction must be clear and unambiguous |
| **Finiteness** | Algorithm must terminate after a finite number of steps |
| **Effectiveness** | Every instruction must be basic enough to be carried out |

### 1.3 How to Write an Algorithm

```
Algorithm: Finding Maximum of Two Numbers
Step 1: Start
Step 2: Read two numbers A and B
Step 3: If A > B then
           Print "A is maximum"
        Else
           Print "B is maximum"
Step 4: Stop
```

### 1.4 Algorithm vs Program

| Algorithm | Program |
|-----------|---------|
| Written in natural language/pseudo-code | Written in programming language |
| Language independent | Language dependent |
| Design phase | Implementation phase |
| Analyzed by priori analysis | Analyzed by posteriori analysis |

---

## 2. Complexity Analysis

### 2.1 What is Complexity?
**Complexity** measures the efficiency of an algorithm in terms of:
- **Time Complexity**: Amount of time taken by an algorithm to run
- **Space Complexity**: Amount of memory space required by an algorithm

### 2.2 Types of Analysis

#### a) Priori Analysis (Theoretical)
- Done before implementation
- Independent of hardware/language
- Uses asymptotic notations

#### b) Posteriori Analysis (Empirical)
- Done after implementation
- Depends on hardware/language
- Uses actual time and space measurements

### 2.3 Time Complexity

Time complexity depends on the input size (n). We count the number of basic operations.

**Example:**
```c
// Simple Loop - O(n)
for(i = 0; i < n; i++) {
    printf("%d", i);  // Executes n times
}

// Nested Loop - O(n²)
for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
        printf("%d", i+j);  // Executes n×n times
    }
}
```

### 2.4 Space Complexity

Space complexity = **Fixed Part + Variable Part**

- **Fixed Part**: Space for code, simple variables, constants
- **Variable Part**: Space for dynamic allocation, recursion stack

**Example:**
```c
int sum(int arr[], int n) {
    int total = 0;           // 1 variable
    for(int i = 0; i < n; i++) {  // 1 variable
        total += arr[i];
    }
    return total;
}
// Space Complexity: O(1) - constant extra space
```

### 2.5 Cases of Complexity

| Case | Description | Example (Linear Search) |
|------|-------------|------------------------|
| **Best Case** | Minimum time required | Element found at first position: O(1) |
| **Average Case** | Average time for all inputs | Element found at middle: O(n/2) |
| **Worst Case** | Maximum time required | Element at last or not found: O(n) |

---

## 3. Asymptotic Notations

Asymptotic notations describe the **growth rate** of algorithms as input size approaches infinity.

### 3.1 Big-O Notation (O) — Upper Bound

**Definition:** f(n) = O(g(n)) if there exist positive constants c and n₀ such that:
> **0 ≤ f(n) ≤ c·g(n)** for all n ≥ n₀

**Meaning:** f(n) grows at most as fast as g(n)

**Example:**
- f(n) = 3n + 2
- For n ≥ 2: 3n + 2 ≤ 4n
- Therefore, f(n) = O(n) with c = 4, n₀ = 2

```
Graph Representation:
        ↑
   c·g(n)─────────────╱
        │           ╱
   f(n) │       ╱
        │   ╱
        └─────────────→ n
            n₀
```

### 3.2 Omega Notation (Ω) — Lower Bound

**Definition:** f(n) = Ω(g(n)) if there exist positive constants c and n₀ such that:
> **0 ≤ c·g(n) ≤ f(n)** for all n ≥ n₀

**Meaning:** f(n) grows at least as fast as g(n)

**Example:**
- f(n) = 3n + 2
- For n ≥ 1: 3n + 2 ≥ 3n ≥ n
- Therefore, f(n) = Ω(n) with c = 1, n₀ = 1

### 3.3 Theta Notation (Θ) — Tight Bound

**Definition:** f(n) = Θ(g(n)) if there exist positive constants c₁, c₂ and n₀ such that:
> **c₁·g(n) ≤ f(n) ≤ c₂·g(n)** for all n ≥ n₀

**Meaning:** f(n) grows exactly at the same rate as g(n)

**Example:**
- f(n) = 3n + 2
- For n ≥ 2: n ≤ 3n + 2 ≤ 4n
- Therefore, f(n) = Θ(n) with c₁ = 1, c₂ = 4, n₀ = 2

### 3.4 Little-o Notation (o) — Strict Upper Bound

**Definition:** f(n) = o(g(n)) if:
> lim (n→∞) [f(n)/g(n)] = 0

**Meaning:** f(n) grows strictly slower than g(n)

### 3.5 Little-omega Notation (ω) — Strict Lower Bound

**Definition:** f(n) = ω(g(n)) if:
> lim (n→∞) [f(n)/g(n)] = ∞

**Meaning:** f(n) grows strictly faster than g(n)

### 3.6 Comparison of Asymptotic Notations

| Notation | Symbol | Meaning | Analogy |
|----------|--------|---------|---------|
| Big-O | O | Upper Bound | ≤ (less than or equal) |
| Big-Omega | Ω | Lower Bound | ≥ (greater than or equal) |
| Theta | Θ | Tight Bound | = (equal) |
| Little-o | o | Strict Upper Bound | < (strictly less) |
| Little-omega | ω | Strict Lower Bound | > (strictly greater) |

### 3.7 Common Time Complexities (Ordered)

| Complexity | Name | Example |
|------------|------|---------|
| O(1) | Constant | Array access |
| O(log n) | Logarithmic | Binary Search |
| O(n) | Linear | Linear Search |
| O(n log n) | Linearithmic | Merge Sort, Quick Sort |
| O(n²) | Quadratic | Bubble Sort, Selection Sort |
| O(n³) | Cubic | Matrix Multiplication |
| O(2ⁿ) | Exponential | Recursive Fibonacci |
| O(n!) | Factorial | Permutations |

---

## 4. Solving Recurrences

**Recurrence relation** is an equation that defines a sequence recursively.

### 4.1 Methods to Solve Recurrences

1. **Substitution Method**
2. **Recursion Tree Method**
3. **Master's Theorem**

---

### 4.2 Substitution Method

**Steps:**
1. Guess the form of the solution
2. Use mathematical induction to verify
3. Solve for constants

**Example:** T(n) = 2T(n/2) + n

**Guess:** T(n) = O(n log n), i.e., T(n) ≤ cn log n

**Proof by induction:**
- Assume T(n/2) ≤ c(n/2)log(n/2)
- T(n) = 2T(n/2) + n
- T(n) ≤ 2·c(n/2)log(n/2) + n
- T(n) ≤ cn·log(n/2) + n
- T(n) ≤ cn·log n - cn·log 2 + n
- T(n) ≤ cn·log n - cn + n
- T(n) ≤ cn·log n (for c ≥ 1)

**Therefore, T(n) = O(n log n)**

---

### 4.3 Recursion Tree Method

**Steps:**
1. Draw the recursion tree
2. Calculate cost at each level
3. Sum up all levels

**Example:** T(n) = 2T(n/2) + n²

```
Level 0:              n²                    Cost: n²
                    /    \
Level 1:       (n/2)²   (n/2)²              Cost: 2×(n/2)² = n²/2
                /  \     /  \
Level 2:    (n/4)²...             ...       Cost: 4×(n/4)² = n²/4
              ...
Level k:    T(1) T(1) ... T(1)              Cost: 2^k × (n/2^k)²
```

- Number of levels: log n
- Total cost = n² + n²/2 + n²/4 + ... = n²(1 + 1/2 + 1/4 + ...) = n² × 2 = **O(n²)**

---

### 4.4 Master's Theorem

For recurrences of the form:
> **T(n) = aT(n/b) + f(n)**

Where a ≥ 1, b > 1, and f(n) is asymptotically positive

**Let n^(log_b(a)) be the critical exponent**

#### Case 1: If f(n) = O(n^(log_b(a) - ε)) for some ε > 0
> **T(n) = Θ(n^(log_b(a)))**

#### Case 2: If f(n) = Θ(n^(log_b(a)))
> **T(n) = Θ(n^(log_b(a)) × log n)**

#### Case 3: If f(n) = Ω(n^(log_b(a) + ε)) for some ε > 0
And if af(n/b) ≤ cf(n) for some c < 1 (regularity condition)
> **T(n) = Θ(f(n))**

### 4.5 Master's Theorem Examples

#### Example 1: T(n) = 2T(n/2) + n
- a = 2, b = 2, f(n) = n
- n^(log₂2) = n¹ = n
- f(n) = n = Θ(n^(log_b(a)))
- **Case 2 applies: T(n) = Θ(n log n)**

#### Example 2: T(n) = 4T(n/2) + n
- a = 4, b = 2, f(n) = n
- n^(log₂4) = n²
- f(n) = n = O(n^(2-1)) = O(n^(2-ε)) where ε = 1
- **Case 1 applies: T(n) = Θ(n²)**

#### Example 3: T(n) = T(n/2) + n²
- a = 1, b = 2, f(n) = n²
- n^(log₂1) = n⁰ = 1
- f(n) = n² = Ω(n^(0+2)) = Ω(n^ε) where ε = 2
- **Case 3 applies: T(n) = Θ(n²)**

#### Example 4: T(n) = 2T(n/2) + n log n
- a = 2, b = 2, f(n) = n log n
- n^(log₂2) = n
- f(n) = n log n ≠ Θ(n^k) for any k
- **Master's theorem doesn't apply directly** (use extended version)

---

## 5. Summary Table

| Topic | Key Points |
|-------|------------|
| Algorithm | Finite steps, must terminate, clear instructions |
| Time Complexity | Number of operations as function of input size |
| Space Complexity | Memory used as function of input size |
| Big-O | Upper bound (worst case) |
| Omega | Lower bound (best case) |
| Theta | Tight bound (average case) |
| Master's Theorem | For divide and conquer recurrences T(n) = aT(n/b) + f(n) |

---

## 📝 Important Questions

1. Define Algorithm. What are its characteristics?
2. Explain the different types of asymptotic notations with examples.
3. What is the difference between Big-O, Omega, and Theta notation?
4. Solve using Master's Theorem: T(n) = 4T(n/2) + n²
5. Explain the Recursion Tree method with an example.
6. What is the difference between time complexity and space complexity?
7. Solve the recurrence T(n) = 2T(n/2) + n using substitution method.

---

## 📖 References
- Horowitz E - Computer Algorithms, Galgotia Publication
- Aho A.V, Hopcroft J.E & Ullman J.D - The Design and Analysis of Computer Algorithm, Addison Wesley
