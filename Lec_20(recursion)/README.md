# Lecture 20 - Recursion

Recursion is when a function **calls itself** to solve a smaller version of the same problem. Every recursive function needs:
1. **Base Case** – the condition where the function stops calling itself.
2. **Recursive Case** – where the function calls itself with a smaller/simpler input.

---

## Recurrence Relation

A recurrence relation describes the time/space complexity of a recursive function in terms of smaller inputs.

| Problem | Recurrence | Result |
|---------|-----------|--------|
| Factorial | T(n) = T(n-1) + O(1) | O(n) |
| Fibonacci | T(n) = T(n-1) + T(n-2) + O(1) | O(2^n) |
| Merge Sort | T(n) = 2T(n/2) + O(n) | O(n log n) |
| Binary Search | T(n) = T(n/2) + O(1) | O(log n) |

---

## Files Overview

---

### Code1.cpp – Basic Recursion Problems

**1. Print Numbers from N to 1**
```
printNums(5) → 5 4 3 2 1
```
- Print `n`, then call `printNums(n-1)`.
- Stop when `n == 1`.

**2. Factorial**
```
factorial(5) = 5 × 4 × 3 × 2 × 1 = 120
```
- `factorial(n)` = `n × factorial(n-1)`
- Base case: `factorial(0) = 1`, `factorial(1) = 1`

**3. Sum of N Natural Numbers**
```
sumOfN(5) = 5 + 4 + 3 + 2 + 1 = 15
```
- `sumOfN(n)` = `n + sumOfN(n-1)`
- Base case: `sumOfN(1) = 1`

**4. Fibonacci**
```
fibonacci(6) → 0 1 1 2 3 5 8
fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
```
- Base cases: `fibonacci(0) = 0`, `fibonacci(1) = 1`
- ⚠️ This naive version is O(2^n) — slow for large n.

**5. Is Array Sorted?**
```
arr = [1, 2, 3, 4] → true
arr = [1, 3, 2, 4] → false
```
- Check if last element >= second last, then recurse on smaller array.
- Base case: array of size 0 or 1 is always sorted.

**6. Binary Search (Recursive)**
```
arr = [1, 3, 5, 7, 9], target = 5 → index 2
```
- Calculate `mid`. If `arr[mid] == target`, return `mid`.
- If target is smaller, search left half; otherwise search right half.
- Base case: `start > end` → element not found.

---

### Code2.cpp – All Subsets (Power Set)

**Problem (LeetCode 78):** Given array `[1, 2, 3]`, print all subsets including empty set.

```
Output: [], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]
```

**Logic:**
For each element, you have **two choices**:
1. **Include** the element → add to current subset, recurse on next index.
2. **Exclude** the element → remove (backtrack), recurse on next index.

```
                    []
           /                \
         [1]                []
        /    \            /    \
     [1,2]  [1]        [2]    []
     /  \   / \        / \   / \
  [1,2,3][1,2][1,3]  [1][2,3][2][3][]
```

This is called **backtracking** — undo a choice and try the other option.

---

### Code3.cpp – All Permutations (LeetCode 46)

**Problem:** Given `nums = [1,2,3]`, return all possible orderings.

```
Output: [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]
```

**Logic:**
- Fix one element at position `idx` by swapping it with every element from `idx` to end.
- Recurse for `idx + 1`.
- Swap back (backtrack) to restore original order.

```
[1,2,3]
├── swap(0,0) → [1,2,3] → fix 1, permute [2,3]
├── swap(0,1) → [2,1,3] → fix 2, permute [1,3]
└── swap(0,2) → [3,2,1] → fix 3, permute [2,1]
```

---

### Code4.cpp – N-Queens (LeetCode 51) — Hard

**Problem:** Place N queens on an N×N chessboard such that no two queens attack each other (same row, column, or diagonal).

```
n = 4 → Output: [".Q..","...Q","Q...","..Q."]
```

**Logic:**
- Try placing a queen in each column of the current row.
- Check if the position is **safe**:
  - No queen in same row
  - No queen in same column
  - No queen on upper-left diagonal
  - No queen on upper-right diagonal
- If safe, place queen and recurse for next row.
- If no column works, backtrack (remove queen).

---

### Code5.cpp – Sudoku Solver (LeetCode 37) — Hard

**Problem:** Fill empty cells (`.`) in a 9×9 sudoku grid following sudoku rules.

**Logic:**
- For each empty cell, try digits `1–9`.
- Check if digit is **safe** (not already in same row, column, or 3×3 box).
- If safe, place digit and recurse to next cell.
- If no digit works, backtrack (reset to `.`).
- If all cells are filled, the board is solved.

---

### Code6.cpp – Rat in a Maze

**Problem:** A rat starts at `(0,0)` and needs to reach `(n-1, n-1)` in a grid. Cells with `0` are blocked. Find all possible paths.

```
mat = {{1,0,0,0},
       {1,1,0,1},
       {1,1,0,0},
       {0,1,1,1}}

Output: "DDRDRR", "DRDDRR"
```

**Directions:** D (Down), U (Up), L (Left), R (Right)

**Logic:**
- At each cell, try all 4 directions.
- Mark current cell as visited (`-1`) to avoid revisiting.
- If destination `(n-1, n-1)` is reached, save the path.
- Backtrack: unmark the cell (`1`) after exploring all directions.

---

### Code7.cpp – Combination Sum (LeetCode 39)

**Problem:** Given candidates `[2,3,6,7]` and target `7`, find all combinations that sum to target. Same number can be used multiple times.

```
Output: [[2,2,3], [7]]
```

**Logic:**
- At each index, three choices:
  1. **Include once** → move to next index, subtract value from target.
  2. **Include again** → stay at same index, subtract value again.
  3. **Exclude** → move to next index, keep target same.
- Base case: `target == 0` → valid combination found.
- Stop if `target < 0` or all elements exhausted.

---

### Code8.cpp – Palindrome Partitioning (LeetCode 131)

**Problem:** Given string `"aab"`, split it into parts where every part is a palindrome.

```
Output: [["a","a","b"], ["aa","b"]]
```

**Logic:**
- Try every possible prefix of the remaining string.
- If the prefix is a **palindrome**, include it and recurse on the rest of the string.
- Backtrack by removing the last added partition.
- Base case: string is empty → all parts are valid, save result.

---

### Code9.cpp – Merge Sort

**Problem:** Sort an array using the divide-and-conquer approach.

```
Input:  [12, 31, 35, 8, 32, 17]
Output: [8, 12, 17, 31, 32, 35]
```

**Logic:**
1. **Divide** the array into two halves at the middle.
2. Recursively sort the left half.
3. Recursively sort the right half.
4. **Merge** both sorted halves into one sorted array.

```
[12, 31, 35, 8, 32, 17]
       /            \
[12, 31, 35]    [8, 32, 17]
   /    \          /     \
[12] [31,35]   [8]   [32,17]
      / \              / \
    [31] [35]        [32] [17]
      → merge →      → merge →
     [31,35]          [17,32]
  → merge →         → merge →
[12,31,35]         [8,17,32]
        → final merge →
    [8,12,17,31,32,35]
```

**Time:** O(n log n) | **Space:** O(n)

---

### Code10.cpp – Quick Sort

**Problem:** Sort an array using a pivot element.

```
Input:  [12, 31, 35, 8, 32, 17]
Output: [8, 12, 17, 31, 32, 35]
```

**Logic:**
1. Pick the **last element as pivot**.
2. **Partition** – move all elements smaller than pivot to its left, larger to its right.
3. Pivot is now at its correct sorted position.
4. Recursively sort the left and right halves.

```
[12, 31, 35, 8, 32, 17]  pivot = 17
After partition: [12, 8, 17, 35, 32, 31]  → 17 is at index 2
Left: [12, 8]   Right: [35, 32, 31]
...recursively sort both...
Final: [8, 12, 17, 31, 32, 35]
```

**Time:** O(n log n) avg, O(n²) worst | **Space:** O(log n)

---

### Code11.cpp – Count Inversions

**Problem:** Count pairs `(i, j)` where `i < j` but `arr[i] > arr[j]`.

```
Input:  [6, 3, 5, 2, 7]
Inversions: (6,3), (6,5), (6,2), (3,2), (5,2) → count = 5
```

**Logic:**
- Uses a modified **Merge Sort**.
- During the merge step, when an element from the right half is placed before an element in the left half, all remaining elements in the left half form inversions with it.
- `invCount += (mid - i + 1)` counts them all at once.

**Time:** O(n log n)

---

### Code12.cpp – Check Knight Tour Configuration (LeetCode 2596)

**Problem:** Verify if a given grid represents a valid knight's tour (knight visits every cell exactly once starting from top-left).

```
grid[row][col] = the step number at which the knight visited that cell
```

**Logic:**
- Start at `(0, 0)` which should have value `0`.
- A knight moves in an **L-shape**: 2 squares in one direction + 1 square perpendicular.
- There are **8 possible moves** from any cell.
- Recursively check if any of the 8 moves leads to the cell with value `expVal + 1`.
- Base case: if `expVal == n*n - 1`, all cells visited → return `true`.

```
8 possible knight moves from (r, c):
(-2,+1) (-1,+2) (+1,+2) (+2,+1)
(+2,-1) (+1,-2) (-1,-2) (-2,-1)
```

---

## Key Concepts

### Backtracking
Try a choice → recurse → undo the choice if it doesn't lead to a solution.
Used in: Subsets, Permutations, N-Queens, Sudoku, Rat in a Maze, Palindrome Partitioning.

### Divide and Conquer
Split the problem into smaller subproblems, solve each, and combine results.
Used in: Merge Sort, Quick Sort, Binary Search.

### Include / Exclude Pattern
At each step decide whether to include or exclude the current element.
Used in: Subsets, Combination Sum.

---

## Complexity Summary

| File | Problem | Time | Space |
|------|---------|------|-------|
| Code1 | Basic recursion | O(n) | O(n) |
| Code2 | All Subsets | O(2^n) | O(n) |
| Code3 | Permutations | O(n! × n) | O(n) |
| Code4 | N-Queens | O(n!) | O(n²) |
| Code5 | Sudoku Solver | O(9^m) | O(1) |
| Code6 | Rat in a Maze | O(4^(n²)) | O(n²) |
| Code7 | Combination Sum | O(2^target) | O(target) |
| Code8 | Palindrome Partition | O(n × 2^n) | O(n) |
| Code9 | Merge Sort | O(n log n) | O(n) |
| Code10 | Quick Sort | O(n log n) avg | O(log n) |
| Code11 | Count Inversions | O(n log n) | O(n) |
| Code12 | Knight Tour Check | O(8^(n²)) | O(n²) |
