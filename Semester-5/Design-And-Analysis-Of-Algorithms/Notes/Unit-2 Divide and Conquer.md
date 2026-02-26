# UNIT 2: DIVIDE AND CONQUER
### BCA C5002 — Design and Analysis of Algorithms

---

## TABLE OF CONTENTS

1. [Introduction to Divide and Conquer](#1-introduction-to-divide-and-conquer)
2. [General Algorithm (Control Abstraction)](#2-general-algorithm-control-abstraction)
3. [Binary Search](#3-binary-search)
4. [Finding Maximum and Minimum](#4-finding-maximum-and-minimum)
5. [Merge Sort](#5-merge-sort)
6. [Quick Sort](#6-quick-sort)
7. [Comparison Summary Table](#7-comparison-summary-table)
8. [How to Measure Complexity Step by Step](#8-how-to-measure-complexity-step-by-step)

---

## 1. Introduction to Divide and Conquer

### 1.1 What is Divide and Conquer?

Divide and Conquer is a fundamental algorithm design paradigm that solves a problem by:

1. **Divide** — Break the original problem into two or more smaller sub-problems of the same type.
2. **Conquer** — Solve each sub-problem recursively. If the sub-problem is small enough (base case), solve it directly.
3. **Combine** — Merge or combine the solutions of the sub-problems to produce the solution to the original problem.

### 1.2 Key Characteristics

- Sub-problems must be **independent** (non-overlapping) — this distinguishes it from Dynamic Programming.
- The structure naturally leads to **recursive** implementations.
- Time complexity is typically expressed using a **recurrence relation** solved via the Master Theorem.

### 1.3 Master Theorem (for Recurrences)

For recurrences of the form:

```
T(n) = aT(n/b) + f(n)
```

Where:
- `a` = number of sub-problems
- `b` = factor by which input size shrinks
- `f(n)` = cost of dividing and combining

**Three cases:**

| Case | Condition | Result |
|------|-----------|--------|
| Case 1 | f(n) = O(n^(log_b(a) - ε)) | T(n) = Θ(n^log_b(a)) |
| Case 2 | f(n) = Θ(n^log_b(a)) | T(n) = Θ(n^log_b(a) * log n) |
| Case 3 | f(n) = Ω(n^(log_b(a) + ε)) | T(n) = Θ(f(n)) |

---

## 2. General Algorithm (Control Abstraction)

The general Divide and Conquer strategy can be expressed as a template:

### 2.1 Pseudocode

```
Algorithm DAndC(P)
{
    if Small(P) then
        return S(P);          // Base case: solve directly
    else
    {
        divide P into smaller instances P1, P2, ..., Pk  // Divide step
        Apply DAndC to each of these sub-problems         // Conquer step
        return Combine(DAndC(P1), DAndC(P2), ..., DAndC(Pk));  // Combine step
    }
}
```

### 2.2 Explanation of Each Part

- **`Small(P)`** — A predicate function that returns TRUE when the problem P is small enough to be solved without further division (the base case).
- **`S(P)`** — A function that directly solves small instances of P.
- **`Combine(...)`** — A function that merges sub-problem solutions into the final answer.

### 2.3 Recurrence for General D&C

If a problem of size `n` is divided into `a` sub-problems each of size `n/b`, with `g(n)` work to divide and combine:

```
T(n) = aT(n/b) + g(n)    for n > threshold
T(n) = c                  for n <= threshold (base case)
```

---

## 3. Binary Search

### 3.1 Concept

Binary Search finds a target element `x` in a **sorted array** by repeatedly halving the search space. At each step it compares `x` with the middle element and discards the half where `x` cannot be.

### 3.2 Divide and Conquer View

- **Divide:** Find the middle index `mid = (low + high) / 2`.
- **Conquer:** Search only the left half or right half.
- **Combine:** No combining needed — the answer is found directly.

### 3.3 General Algorithm (Pseudocode)

```
Algorithm BinarySearch(A, low, high, x)
    Input:  Sorted array A[0..n-1], search bounds low and high, target x
    Output: Index of x in A, or -1 if not found

    if low > high then
        return -1           // Base case: element not found

    mid = (low + high) / 2

    if A[mid] == x then
        return mid          // Element found

    else if x < A[mid] then
        return BinarySearch(A, low, mid - 1, x)    // Search left half

    else
        return BinarySearch(A, mid + 1, high, x)   // Search right half
```

### 3.4 Recursive Implementation in C++

```cpp
#include <iostream>
using namespace std;

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int x) {
    // Base case: element not found
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;  // Avoids integer overflow

    // Element found
    if (arr[mid] == x)
        return mid;

    // Search left half
    else if (x < arr[mid])
        return binarySearchRecursive(arr, low, mid - 1, x);

    // Search right half
    else
        return binarySearchRecursive(arr, mid + 1, high, x);
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int n = 10;
    int x = 23;

    int result = binarySearchRecursive(arr, 0, n - 1, x);

    if (result != -1)
        cout << "Element " << x << " found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
```

### 3.5 Non-Recursive (Iterative) Implementation in C++

```cpp
#include <iostream>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Safe mid calculation

        if (arr[mid] == x)
            return mid;             // Found

        else if (x < arr[mid])
            high = mid - 1;         // Discard right half

        else
            low = mid + 1;          // Discard left half
    }
    return -1;  // Not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int n = 10;
    int x = 38;

    int result = binarySearchIterative(arr, n, x);

    if (result != -1)
        cout << "Element " << x << " found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
```

### 3.6 Step-by-Step Trace (Example)

**Array:** `{2, 5, 8, 12, 16, 23, 38, 45}`, **Search for x = 23**

| Step | low | high | mid | A[mid] | Decision |
|------|-----|------|-----|--------|----------|
| 1 | 0 | 7 | 3 | 12 | x > 12 → go right |
| 2 | 4 | 7 | 5 | 23 | x == 23 → FOUND at index 5 |

### 3.7 Time and Space Complexity

**Recurrence:**
```
T(n) = T(n/2) + O(1)
```

Using Master Theorem: a=1, b=2, f(n)=O(1), log_b(a) = log_2(1) = 0 → Case 2

| Case | Complexity |
|------|-----------|
| Best Case | O(1) — element found at midpoint |
| Average Case | O(log n) |
| Worst Case | O(log n) — element not present |

| Version | Space Complexity |
|---------|-----------------|
| Recursive | O(log n) — recursion call stack |
| Iterative | O(1) — no extra space |

### 3.8 Advantages and Disadvantages

**Advantages:**
- Very fast — O(log n) vs O(n) for linear search
- Simple to implement

**Disadvantages:**
- Array must be **sorted** beforehand
- Random access required — does not work on linked lists efficiently
- Extra overhead for small arrays (linear search may be faster for n < ~20)

---

## 4. Finding Maximum and Minimum

### 4.1 Concept

Given an array of `n` elements, find both the **maximum** and **minimum** values simultaneously using the fewest number of comparisons.

**Naive approach:** Finding max requires n-1 comparisons, finding min requires n-1 comparisons → **total: 2(n-1) comparisons**.

**Divide and Conquer approach:** Achieves it in approximately **3n/2 - 2 comparisons** — a significant improvement.

### 4.2 Divide and Conquer View

- **Divide:** Split the array into two halves.
- **Conquer:** Recursively find (max, min) of each half.
- **Combine:** Compare the two maxima and two minima → 2 comparisons.

### 4.3 General Algorithm (Pseudocode)

```
Algorithm MaxMin(A, low, high)
    Input:  Array A, index range [low, high]
    Output: (max, min) pair

    if low == high then
        return (A[low], A[low])         // Single element: max = min

    if high == low + 1 then             // Two elements
        if A[low] > A[high] then
            return (A[low], A[high])
        else
            return (A[high], A[low])

    mid = (low + high) / 2

    (lmax, lmin) = MaxMin(A, low, mid)       // Conquer left half
    (rmax, rmin) = MaxMin(A, mid+1, high)    // Conquer right half

    return (max(lmax, rmax), min(lmin, rmin))  // Combine
```

### 4.4 Recursive Implementation in C++

```cpp
#include <iostream>
#include <climits>
using namespace std;

struct Pair {
    int maxVal, minVal;
};

// Recursive Max-Min using Divide and Conquer
Pair maxMin(int arr[], int low, int high) {
    Pair result, left, right;

    // Base case: single element
    if (low == high) {
        result.maxVal = arr[low];
        result.minVal = arr[low];
        return result;
    }

    // Base case: two elements — 1 comparison
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.maxVal = arr[low];
            result.minVal = arr[high];
        } else {
            result.maxVal = arr[high];
            result.minVal = arr[low];
        }
        return result;
    }

    // Divide
    int mid = (low + high) / 2;

    // Conquer
    left  = maxMin(arr, low, mid);
    right = maxMin(arr, mid + 1, high);

    // Combine — 2 comparisons
    result.maxVal = (left.maxVal > right.maxVal) ? left.maxVal : right.maxVal;
    result.minVal = (left.minVal < right.minVal) ? left.minVal : right.minVal;

    return result;
}

int main() {
    int arr[] = {3, 1, 8, 6, 2, 9, 4, 7};
    int n = 8;

    Pair result = maxMin(arr, 0, n - 1);
    cout << "Maximum: " << result.maxVal << endl;
    cout << "Minimum: " << result.minVal << endl;

    return 0;
}
```

### 4.5 Non-Recursive (Iterative) Implementation in C++

```cpp
#include <iostream>
using namespace std;

// Iterative approach — pairwise comparison technique
// Comparisons: 3*floor(n/2)
void maxMinIterative(int arr[], int n, int &maxVal, int &minVal) {
    int i;

    // Initialize max and min
    if (n % 2 == 0) {
        // Even: compare first pair
        if (arr[0] > arr[1]) { maxVal = arr[0]; minVal = arr[1]; }
        else                  { maxVal = arr[1]; minVal = arr[0]; }
        i = 2;
    } else {
        // Odd: set first element as both max and min
        maxVal = minVal = arr[0];
        i = 1;
    }

    // Process remaining elements in pairs
    while (i < n - 1) {
        int localMax, localMin;
        if (arr[i] > arr[i + 1]) {  // 1 comparison
            localMax = arr[i];
            localMin = arr[i + 1];
        } else {
            localMax = arr[i + 1];
            localMin = arr[i];
        }
        if (localMax > maxVal) maxVal = localMax;  // 1 comparison
        if (localMin < minVal) minVal = localMin;  // 1 comparison
        i += 2;  // process 2 elements, 3 comparisons (vs 4 naive)
    }
}

int main() {
    int arr[] = {3, 1, 8, 6, 2, 9, 4, 7};
    int n = 8;
    int maxVal, minVal;

    maxMinIterative(arr, n, maxVal, minVal);
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;

    return 0;
}
```

### 4.6 Step-by-Step Trace

**Array:** `{3, 1, 8, 6}` (n=4)

```
MaxMin(A, 0, 3)
├── MaxMin(A, 0, 1) → compare 3 and 1 → (max=3, min=1)
├── MaxMin(A, 2, 3) → compare 8 and 6 → (max=8, min=6)
└── Combine: max(3,8)=8, min(1,6)=1 → (max=8, min=1)
```

Total comparisons: 1 + 1 + 2 = **4 comparisons** (vs 6 naive for n=4)

### 4.7 Comparison Count Analysis

| Approach | Number of Comparisons |
|----------|-----------------------|
| Naive (two passes) | 2(n - 1) |
| Divide and Conquer | 3n/2 - 2 (for n even) |

### 4.8 Time and Space Complexity

**Recurrence:**
```
T(n) = 2T(n/2) + 2    (2 comparisons to combine)
T(2) = 1              (base case: 1 comparison)
```

**Solution:** T(n) = 3n/2 - 2

| Metric | Value |
|--------|-------|
| Time Complexity | O(n) |
| Space Complexity (Recursive) | O(log n) — call stack |
| Space Complexity (Iterative) | O(1) |

---

## 5. Merge Sort

### 5.1 Concept

Merge Sort is a classic Divide and Conquer sorting algorithm. It divides the array into halves, recursively sorts each half, then **merges** the two sorted halves into one sorted array.

### 5.2 Divide and Conquer View

- **Divide:** Split array of n elements into two halves of n/2 elements each.
- **Conquer:** Recursively sort each half.
- **Combine:** Merge the two sorted halves — the key step, costs O(n).

### 5.3 General Algorithm (Pseudocode)

```
Algorithm MergeSort(A, low, high)
    Input:  Array A with indices low to high
    Output: Sorted array A

    if low < high then
        mid = (low + high) / 2
        MergeSort(A, low, mid)         // Sort left half
        MergeSort(A, mid + 1, high)    // Sort right half
        Merge(A, low, mid, high)       // Combine sorted halves

Algorithm Merge(A, low, mid, high)
    Create temporary arrays L[0..mid-low] and R[0..high-mid-1]
    Copy A[low..mid] into L
    Copy A[mid+1..high] into R

    i = 0, j = 0, k = low
    while i < length(L) and j < length(R) do
        if L[i] <= R[j] then
            A[k] = L[i]; i++
        else
            A[k] = R[j]; j++
        k++

    // Copy remaining elements
    while i < length(L) do A[k] = L[i]; i++; k++
    while j < length(R) do A[k] = R[j]; j++; k++
```

### 5.4 Recursive Implementation in C++

```cpp
#include <iostream>
using namespace std;

// Merge two sorted subarrays: A[low..mid] and A[mid+1..high]
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;   // Size of left subarray
    int n2 = high - mid;       // Size of right subarray

    // Create temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) L[i] = arr[low + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back
    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {    // <= ensures stability
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while (i < n1) { arr[k] = L[i]; i++; k++; }

    // Copy remaining elements of R[]
    while (j < n2) { arr[k] = R[j]; j++; k++; }

    delete[] L;
    delete[] R;
}

// Recursive Merge Sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) {   // Base case: single element (low == high) is already sorted
        int mid = low + (high - low) / 2;  // Prevents overflow

        mergeSort(arr, low, mid);       // Sort left half
        mergeSort(arr, mid + 1, high);  // Sort right half
        merge(arr, low, mid, high);     // Merge sorted halves
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}
```

### 5.5 Non-Recursive (Bottom-Up / Iterative) Implementation in C++

```cpp
#include <iostream>
using namespace std;

// Bottom-Up Merge Sort (Iterative)
// No recursion — merges subarrays of increasing size: 1, 2, 4, 8, ...

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[low + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSortIterative(int arr[], int n) {
    // curr_size: current size of subarrays to be merged
    // Starts from 1, doubles each pass: 1, 2, 4, 8, ...
    for (int currSize = 1; currSize < n; currSize *= 2) {

        // Merge subarrays in current pass
        for (int low = 0; low < n - 1; low += 2 * currSize) {

            int mid  = min(low + currSize - 1, n - 1);
            int high = min(low + 2 * currSize - 1, n - 1);

            if (mid < high)  // Ensure there are two parts to merge
                merge(arr, low, mid, high);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    cout << "Original array: ";
    printArray(arr, n);

    mergeSortIterative(arr, n);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}
```

### 5.6 Step-by-Step Trace

**Array:** `{38, 27, 43, 3}`

```
Pass 1 — Divide:
[38, 27, 43, 3]
├── [38, 27]
│   ├── [38]   (base case)
│   └── [27]   (base case)
│   └── Merge → [27, 38]
└── [43, 3]
    ├── [43]   (base case)
    └── [3]    (base case)
    └── Merge → [3, 43]

Pass 2 — Combine:
Merge [27, 38] and [3, 43]
  Compare 27 and 3  → take 3  → [3]
  Compare 27 and 43 → take 27 → [3, 27]
  Compare 38 and 43 → take 38 → [3, 27, 38]
  Remaining 43      → take 43 → [3, 27, 38, 43]

Final: [3, 27, 38, 43]
```

### 5.7 Time and Space Complexity

**Recurrence:**
```
T(n) = 2T(n/2) + O(n)    (divide into 2 halves + O(n) merge)
T(1) = O(1)
```

Using Master Theorem: a=2, b=2, f(n)=n, log_b(a)=1 → Case 2

| Case | Complexity |
|------|-----------|
| Best Case | O(n log n) — always divides evenly |
| Average Case | O(n log n) |
| Worst Case | O(n log n) — always same regardless of input |

| Version | Space Complexity |
|---------|-----------------|
| Recursive | O(n) auxiliary + O(log n) stack = O(n) |
| Iterative | O(n) auxiliary only |

### 5.8 Properties of Merge Sort

- **Stable Sort** — Equal elements maintain their original relative order.
- **Out-of-place** — Requires O(n) extra memory (unlike in-place sorts like Quick Sort).
- **Preferred for:** Linked lists (no random access needed), external sorting (data on disk), when stability is required.

---

## 6. Quick Sort

### 6.1 Concept

Quick Sort selects a **pivot** element and **partitions** the array into two parts: elements less than the pivot and elements greater than the pivot. It then recursively sorts each part.

### 6.2 Divide and Conquer View

- **Divide:** Partition the array around a pivot element. After partitioning, the pivot is in its **final sorted position**.
- **Conquer:** Recursively sort the left and right sub-arrays.
- **Combine:** No combining needed — the array is sorted in place.

### 6.3 Pivot Selection Strategies

| Strategy | Description | Effect |
|----------|-------------|--------|
| Last element | Always pick arr[high] | Simple, but O(n²) on sorted input |
| First element | Always pick arr[low] | Simple, same worst-case risk |
| Random element | Pick a random index | Reduces worst-case probability |
| Median-of-three | Median of first, mid, last | Best practical choice |

### 6.4 General Algorithm (Pseudocode)

```
Algorithm QuickSort(A, low, high)
    Input:  Array A, index bounds low and high
    Output: Sorted array A in-place

    if low < high then
        pivotIndex = Partition(A, low, high)   // Partition and place pivot
        QuickSort(A, low, pivotIndex - 1)      // Sort left partition
        QuickSort(A, pivotIndex + 1, high)     // Sort right partition

Algorithm Partition(A, low, high)
    pivot = A[high]       // Choose last element as pivot
    i = low - 1           // Index of smaller element

    for j = low to high - 1 do
        if A[j] <= pivot then
            i = i + 1
            swap(A[i], A[j])

    swap(A[i+1], A[high]) // Place pivot in correct position
    return i + 1          // Return pivot index
```

### 6.5 Recursive Implementation in C++

```cpp
#include <iostream>
using namespace std;

// Swap helper
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Lomuto Partition Scheme (pivot = last element)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = low - 1;        // i tracks last element <= pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // Bring smaller element to left side
        }
    }

    swap(arr[i + 1], arr[high]);  // Place pivot in its correct position
    return i + 1;                  // Return pivot's final index
}

// Recursive Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // pi = pivot index (now in final position)

        quickSort(arr, low, pi - 1);   // Sort elements before pivot
        quickSort(arr, pi + 1, high);  // Sort elements after pivot
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}
```

### 6.6 Hoare Partition Scheme (Alternative — More Efficient)

```cpp
// Hoare Partition: uses two pointers from both ends
// Performs fewer swaps on average than Lomuto
int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];  // Pivot is first element
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { i++; } while (arr[i] < pivot);   // Find element >= pivot from left
        do { j--; } while (arr[j] > pivot);   // Find element <= pivot from right

        if (i >= j) return j;  // Partition complete

        swap(arr[i], arr[j]);  // Swap to put them on correct sides
    }
}
```

### 6.7 Non-Recursive (Iterative) Implementation in C++

```cpp
#include <iostream>
#include <stack>
using namespace std;

void swap(int &a, int &b) { int t = a; a = b; b = t; }

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] <= pivot) { i++; swap(arr[i], arr[j]); }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Iterative Quick Sort using explicit stack
void quickSortIterative(int arr[], int low, int high) {
    // Create an auxiliary stack
    stack<int> st;

    // Push initial low and high
    st.push(low);
    st.push(high);

    // Keep popping from stack while it's not empty
    while (!st.empty()) {
        high = st.top(); st.pop();
        low  = st.top(); st.pop();

        if (low < high) {
            int pi = partition(arr, low, high);

            // Push left part indices
            if (pi - 1 > low) {
                st.push(low);
                st.push(pi - 1);
            }

            // Push right part indices
            if (pi + 1 < high) {
                st.push(pi + 1);
                st.push(high);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    cout << "Original array: ";
    printArray(arr, n);

    quickSortIterative(arr, 0, n - 1);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}
```

### 6.8 Step-by-Step Trace

**Array:** `{10, 7, 8, 9, 1, 5}`, Pivot = 5 (last element)

```
Initial:   [10, 7, 8, 9, 1, 5]   pivot = 5
           i = -1

j=0: arr[0]=10 > 5, skip
j=1: arr[1]=7  > 5, skip
j=2: arr[2]=8  > 5, skip
j=3: arr[3]=9  > 5, skip
j=4: arr[4]=1  ≤ 5, i=0, swap arr[0]↔arr[4] → [1, 7, 8, 9, 10, 5]

End of loop: swap arr[i+1]↔arr[high] = arr[1]↔arr[5]
→ [1, 5, 8, 9, 10, 7]   Pivot 5 is now at index 1 (final position!)

Recurse left:  [1]          — already sorted
Recurse right: [8, 9, 10, 7] — sort further

Final result:  [1, 5, 7, 8, 9, 10]
```

### 6.9 Time and Space Complexity

**Recurrence:**

| Case | Recurrence | Explanation |
|------|-----------|-------------|
| Best | T(n) = 2T(n/2) + O(n) | Pivot always splits evenly |
| Average | T(n) = 2T(n/2) + O(n) | Random pivot, balanced on average |
| Worst | T(n) = T(n-1) + O(n) | Pivot always smallest/largest (sorted array) |

| Case | Time Complexity |
|------|----------------|
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n²) — sorted/reverse-sorted array with bad pivot |

| Version | Space Complexity |
|---------|-----------------|
| Recursive | O(log n) average, O(n) worst-case stack |
| Iterative | O(log n) average, O(n) worst-case explicit stack |

### 6.10 Properties of Quick Sort

- **Unstable Sort** — Does not preserve relative order of equal elements.
- **In-place** — No extra array needed (only O(log n) stack space).
- **Cache-friendly** — Works on contiguous memory; excellent cache performance.
- **Fastest in practice** — Despite O(n²) worst case, average O(n log n) with small constant.

---

## 7. Comparison Summary Table

| Algorithm | Best Time | Average Time | Worst Time | Space | Stable | In-Place |
|-----------|-----------|--------------|------------|-------|--------|----------|
| Binary Search | O(1) | O(log n) | O(log n) | O(log n) / O(1) | N/A | N/A |
| Max-Min (D&C) | O(n) | O(n) | O(n) | O(log n) / O(1) | N/A | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No | Yes |

---

## 8. How to Measure Complexity Step by Step

### 8.1 General Steps to Analyze Any Algorithm

**Step 1: Identify the Basic Operation**
Choose the operation that contributes most to runtime. For sorting: comparisons. For matrix multiply: multiplications. For searching: comparisons.

**Step 2: Count the Operation**
Express the count as a function of input size `n`. Write the recurrence relation if recursive.

**Step 3: Solve the Recurrence**
Use substitution, recursion tree, or Master Theorem.

**Step 4: Express in Asymptotic Notation**
Convert the exact count to O(), Ω(), or Θ() notation.

---

### 8.2 Step-by-Step Analysis: Binary Search

```
T(n) = T(n/2) + 1       // 1 comparison at each level

Step 1: Expand
T(n) = T(n/4) + 1 + 1 = T(n/4) + 2
     = T(n/8) + 3
     = T(n/2^k) + k

Step 2: Base case when n/2^k = 1 → k = log₂n

Step 3: T(n) = T(1) + log₂n = 1 + log₂n

Result: T(n) = O(log n)
```

---

### 8.3 Step-by-Step Analysis: Merge Sort

```
T(n) = 2T(n/2) + n       // 2 subproblems of n/2, n comparisons to merge

Step 1: Draw the recursion tree

Level 0: n           (1 node,  cost = n)
Level 1: n/2, n/2    (2 nodes, cost = n/2 + n/2 = n)
Level 2: n/4 x4      (4 nodes, cost = 4 × n/4 = n)
...
Level k: n/2^k × 2^k (cost = n at every level)

Step 2: Count levels
Tree height = log₂n (stops when subproblem size = 1)

Step 3: Total cost
T(n) = n × (number of levels) = n × log₂n

Result: T(n) = O(n log n)
```

---

### 8.4 Step-by-Step Analysis: Quick Sort (Average Case)

```
T(n) = T(k) + T(n-k-1) + n      // k elements on left, n-k-1 on right, n for partition

Average over all k from 0 to n-1:
T(n) = (2/n) × Σ T(k) + n      (k from 0 to n-1)

This recurrence solves to:
T(n) = O(n log n)

Worst case (pivot always at end, k=0):
T(n) = T(0) + T(n-1) + n = T(n-1) + n
     = n + (n-1) + (n-2) + ... + 1 = n(n+1)/2

Result: Worst case T(n) = O(n²)
```

---

### 8.5 Counting Comparisons: Max-Min

```
Let C(n) = number of comparisons for n elements

Base cases:
  C(1) = 0   (no comparisons for 1 element)
  C(2) = 1   (1 comparison for 2 elements)

Recurrence:
  C(n) = 2C(n/2) + 2    (2 comparisons to combine results)

Solving (for n = 2^k):
  C(2^k) = 2C(2^(k-1)) + 2
          = 2[2C(2^(k-2)) + 2] + 2
          = 4C(2^(k-2)) + 6
          = 2^(k-1) × C(2) + 2^(k-1) - 2    (expanding fully)
          = 2^(k-1) + 2^(k-1) - 2
          = 2^k + 2^(k-1) - 2
          = n + n/2 - 2
          = 3n/2 - 2

Result: Exactly 3n/2 - 2 comparisons (for n even)
```

---

### 8.6 Space Complexity Analysis Guide

| Source of Space | Example | How to Count |
|----------------|---------|--------------|
| Recursion stack depth | Merge Sort, Quick Sort | = height of recursion tree = O(log n) average |
| Auxiliary arrays | Merge Sort's temp arrays | Count extra array sizes |
| In-place operations | Quick Sort partition | Count only swaps (O(1) extra) |

**For recursive algorithms:**
```
Space = (stack frame size) × (max recursion depth)
      = O(1)               × O(log n)
      = O(log n)
```

---

### 8.7 Summary of Recurrences and Solutions

| Algorithm | Recurrence | Solution |
|-----------|-----------|----------|
| Binary Search | T(n) = T(n/2) + O(1) | O(log n) |
| Merge Sort | T(n) = 2T(n/2) + O(n) | O(n log n) |
| Quick Sort (avg) | T(n) = 2T(n/2) + O(n) | O(n log n) |
| Quick Sort (worst) | T(n) = T(n-1) + O(n) | O(n²) |
| Max-Min | T(n) = 2T(n/2) + O(1) | O(n) |

---

*End of Unit 2 — Divide and Conquer*

> **Exam Tips (Q-2 means 2 questions from this unit):**
> - Always write the recurrence relation and its solution.
> - Trace through a small example step by step for full marks.
> - For sorting, compare recursive vs iterative and mention when each is preferred.
> - Mention stability and in-place properties where relevant.
