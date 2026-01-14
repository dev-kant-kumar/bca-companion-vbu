# Unit 2: Divide and Conquer

## 📚 Syllabus Topics
- Binary Search
- Finding Maximum and Minimum
- Merge Sort
- Quick Sort

---

## 1. Divide and Conquer Strategy

### 1.1 What is Divide and Conquer?

**Divide and Conquer** is an algorithm design paradigm that works by recursively breaking down a problem into two or more sub-problems of the same or related type, until these become simple enough to be solved directly.

### 1.2 General Strategy

```
DivideAndConquer(problem P):
    1. DIVIDE: If P is small enough, solve directly (base case)
    2. Otherwise, divide P into smaller sub-problems P1, P2, ..., Pk
    3. CONQUER: Recursively solve each sub-problem
    4. COMBINE: Merge the solutions of sub-problems to get solution of P
```

### 1.3 Recurrence Relation

For a divide and conquer algorithm:
> **T(n) = aT(n/b) + f(n)**

Where:
- **a** = number of sub-problems
- **n/b** = size of each sub-problem
- **f(n)** = cost of dividing and combining

---

## 2. Binary Search

### 2.1 Introduction
Binary Search is an efficient algorithm for finding an element in a **sorted array** by repeatedly dividing the search interval in half.

### 2.2 Algorithm

```
Algorithm: BinarySearch(arr, low, high, key)
Input: Sorted array arr, search bounds low and high, target key
Output: Index of key if found, -1 otherwise

1. If low > high then
      return -1  // Element not found
2. mid = (low + high) / 2
3. If arr[mid] == key then
      return mid  // Element found
4. Else If arr[mid] > key then
      return BinarySearch(arr, low, mid-1, key)  // Search left half
5. Else
      return BinarySearch(arr, mid+1, high, key)  // Search right half
```

### 2.3 Example

**Array:** [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
**Key:** 23

```
Step 1: low=0, high=9, mid=4, arr[4]=16 < 23
        Search right half: low=5, high=9

Step 2: low=5, high=9, mid=7, arr[7]=56 > 23
        Search left half: low=5, high=6

Step 3: low=5, high=6, mid=5, arr[5]=23 == 23
        Found at index 5! ✓
```

### 2.4 Iterative Version

```c
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;  // Not found
}
```

### 2.5 Complexity Analysis

| Aspect | Complexity |
|--------|-----------|
| **Best Case** | O(1) - Element at middle |
| **Average Case** | O(log n) |
| **Worst Case** | O(log n) - Element at end or not present |
| **Space (Iterative)** | O(1) |
| **Space (Recursive)** | O(log n) - Call stack |

### 2.6 Recurrence Relation
> T(n) = T(n/2) + O(1)

Using Master's Theorem: a=1, b=2, f(n)=1
- n^(log₂1) = n⁰ = 1
- Case 2: **T(n) = O(log n)**

---

## 3. Finding Maximum and Minimum

### 3.1 Problem Statement
Given an array of n elements, find both the maximum and minimum elements.

### 3.2 Naive Approach
```c
// Comparisons: 2(n-1) = 2n - 2
void findMinMax(int arr[], int n, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) *max = arr[i];  // n-1 comparisons
        if (arr[i] < *min) *min = arr[i];  // n-1 comparisons
    }
}
```

### 3.3 Divide and Conquer Approach

```
Algorithm: MaxMin(arr, low, high)
Output: (max, min) tuple

1. If low == high then  // Single element
      return (arr[low], arr[low])

2. If high == low + 1 then  // Two elements
      If arr[low] < arr[high] then
         return (arr[high], arr[low])
      Else
         return (arr[low], arr[high])

3. mid = (low + high) / 2

4. (max1, min1) = MaxMin(arr, low, mid)     // Left half
5. (max2, min2) = MaxMin(arr, mid+1, high)  // Right half

6. max = maximum(max1, max2)  // 1 comparison
7. min = minimum(min1, min2)  // 1 comparison

8. return (max, min)
```

### 3.4 Example

**Array:** [3, 8, 1, 9, 4, 6]

```
                    MaxMin(0,5)
                   /          \
          MaxMin(0,2)        MaxMin(3,5)
           /      \           /       \
     MaxMin(0,1) MaxMin(2,2) MaxMin(3,4) MaxMin(5,5)
        ↓           ↓           ↓           ↓
     (8,3)         (1,1)       (9,4)       (6,6)
        \          /              \        /
         \        /                \      /
        (8,1)                      (9,4)
              \                    /
               \                  /
                    (9,1)
                  max=9, min=1
```

### 3.5 Complexity Analysis

**Recurrence Relation:**
> T(n) = 2T(n/2) + 2

**Solution:**
- T(n) = 2T(n/2) + 2
- T(n) = 3n/2 - 2 comparisons

| Method | Comparisons |
|--------|-------------|
| Naive | 2n - 2 |
| Divide & Conquer | 3n/2 - 2 |

**For n = 100:**
- Naive: 198 comparisons
- D&C: 148 comparisons
- **Savings: 50 comparisons!**

---

## 4. Merge Sort

### 4.1 Introduction
Merge Sort is a stable, comparison-based sorting algorithm that uses divide and conquer strategy.

### 4.2 Strategy
1. **Divide:** Split array into two halves
2. **Conquer:** Recursively sort both halves
3. **Combine:** Merge the two sorted halves

### 4.3 Algorithm

```
Algorithm: MergeSort(arr, low, high)
1. If low < high then
      mid = (low + high) / 2
      MergeSort(arr, low, mid)       // Sort left half
      MergeSort(arr, mid+1, high)    // Sort right half
      Merge(arr, low, mid, high)     // Merge sorted halves
```

### 4.4 Merge Procedure

```
Algorithm: Merge(arr, low, mid, high)
1. Create temporary arrays L[] and R[]
2. Copy arr[low..mid] to L[]
3. Copy arr[mid+1..high] to R[]
4. i = 0, j = 0, k = low
5. While i < size(L) and j < size(R)
      If L[i] <= R[j] then
         arr[k] = L[i]
         i = i + 1
      Else
         arr[k] = R[j]
         j = j + 1
      k = k + 1
6. Copy remaining elements of L[] if any
7. Copy remaining elements of R[] if any
```

### 4.5 C Implementation

```c
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    // Merge temp arrays back
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
```

### 4.6 Example

**Array:** [38, 27, 43, 3, 9, 82, 10]

```
          [38, 27, 43, 3, 9, 82, 10]
                    ↓ Divide
        [38, 27, 43, 3]    [9, 82, 10]
              ↓                  ↓
      [38, 27]  [43, 3]    [9, 82]  [10]
        ↓         ↓          ↓        ↓
    [38] [27]  [43] [3]  [9] [82]   [10]
        ↓         ↓          ↓        ↓
      [27, 38]  [3, 43]   [9, 82]   [10]
           ↓                 ↓
       [3, 27, 38, 43]   [9, 10, 82]
                ↓
       [3, 9, 10, 27, 38, 43, 82] ✓
```

### 4.7 Complexity Analysis

**Recurrence Relation:**
> T(n) = 2T(n/2) + n

Using Master's Theorem: a=2, b=2, f(n)=n
- n^(log₂2) = n
- Case 2: **T(n) = Θ(n log n)**

| Aspect | Complexity |
|--------|-----------|
| **Best Case** | O(n log n) |
| **Average Case** | O(n log n) |
| **Worst Case** | O(n log n) |
| **Space** | O(n) - for temporary arrays |
| **Stable** | Yes |

---

## 5. Quick Sort

### 5.1 Introduction
Quick Sort is an efficient, in-place sorting algorithm that uses divide and conquer with a **pivot** element.

### 5.2 Strategy
1. **Choose a pivot** element from the array
2. **Partition:** Rearrange so elements < pivot are on left, elements > pivot are on right
3. **Recursively** apply to left and right sub-arrays

### 5.3 Algorithm

```
Algorithm: QuickSort(arr, low, high)
1. If low < high then
      pivotIndex = Partition(arr, low, high)
      QuickSort(arr, low, pivotIndex - 1)   // Left of pivot
      QuickSort(arr, pivotIndex + 1, high)  // Right of pivot
```

### 5.4 Partition Procedure

```
Algorithm: Partition(arr, low, high)
1. pivot = arr[high]  // Choose last element as pivot
2. i = low - 1        // Index of smaller element

3. For j = low to high - 1
      If arr[j] <= pivot then
         i = i + 1
         Swap arr[i] and arr[j]

4. Swap arr[i + 1] and arr[high]  // Place pivot in correct position
5. Return i + 1                    // Return pivot index
```

### 5.5 C Implementation

```c
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

### 5.6 Example - Partition Process

**Array:** [10, 80, 30, 90, 40, 50, 70] (pivot = 70)

```
Initial: [10, 80, 30, 90, 40, 50, 70]
         i=-1, j=0

j=0: 10 <= 70 → i=0, swap arr[0] with arr[0]
     [10, 80, 30, 90, 40, 50, 70]

j=1: 80 > 70 → no swap
     [10, 80, 30, 90, 40, 50, 70]

j=2: 30 <= 70 → i=1, swap arr[1] with arr[2]
     [10, 30, 80, 90, 40, 50, 70]

j=3: 90 > 70 → no swap

j=4: 40 <= 70 → i=2, swap arr[2] with arr[4]
     [10, 30, 40, 90, 80, 50, 70]

j=5: 50 <= 70 → i=3, swap arr[3] with arr[5]
     [10, 30, 40, 50, 80, 90, 70]

Final: swap arr[i+1] with pivot
     [10, 30, 40, 50, 70, 90, 80]
                    ↑
               Pivot in place!
```

### 5.7 Complexity Analysis

**Recurrence Relations:**

**Best Case (Balanced partitions):**
> T(n) = 2T(n/2) + n = **O(n log n)**

**Worst Case (Already sorted or reverse sorted):**
> T(n) = T(n-1) + n = **O(n²)**

**Average Case:**
> T(n) = **O(n log n)**

| Aspect | Complexity |
|--------|-----------|
| **Best Case** | O(n log n) |
| **Average Case** | O(n log n) |
| **Worst Case** | O(n²) |
| **Space** | O(log n) - for recursion stack |
| **Stable** | No |
| **In-Place** | Yes |

---

## 6. Comparison: Merge Sort vs Quick Sort

| Feature | Merge Sort | Quick Sort |
|---------|------------|------------|
| **Time (Best)** | O(n log n) | O(n log n) |
| **Time (Average)** | O(n log n) | O(n log n) |
| **Time (Worst)** | O(n log n) | O(n²) |
| **Space** | O(n) | O(log n) |
| **Stability** | Stable | Not stable |
| **In-Place** | No | Yes |
| **Cache Performance** | Poor | Better |
| **Best For** | Linked Lists, External Sort | Arrays, In-memory Sort |

---

## 7. Summary Table

| Algorithm | Time Complexity | Space | Key Idea |
|-----------|----------------|-------|----------|
| **Binary Search** | O(log n) | O(1) | Divide search space by half |
| **Max-Min** | O(n) with 3n/2-2 comparisons | O(log n) | Divide and combine extremes |
| **Merge Sort** | O(n log n) | O(n) | Divide, sort, merge |
| **Quick Sort** | O(n log n) avg | O(log n) | Partition around pivot |

---

## 📝 Important Questions

1. Explain Binary Search algorithm with example. Derive its time complexity.
2. Write the algorithm to find maximum and minimum using divide and conquer. Analyze its complexity.
3. Explain Merge Sort with example. Why is it preferred for linked lists?
4. Explain Quick Sort algorithm. What is the worst case and how to avoid it?
5. Compare Merge Sort and Quick Sort.
6. Write the partition procedure of Quick Sort and trace it for [3, 7, 2, 9, 1, 5].
7. What is Divide and Conquer strategy? Give examples.

---

## 📖 References
- Horowitz E - Computer Algorithms, Galgotia Publication
- Aho A.V, Hopcroft J.E & Ullman J.D - The Design and Analysis of Computer Algorithm, Addison Wesley
