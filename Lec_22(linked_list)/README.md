# Lecture 22 - Linked List

A comprehensive study of Linked List data structures and related LeetCode problems in C++.

---

## Topics Covered

| File | Topic | LeetCode | Difficulty |
|------|-------|----------|------------|
| [Lec1.cpp](Lec1.cpp) | Singly Linked List - Implementation | — | Concept |
| [Lec2.cpp](Lec2.cpp) | Reverse Linked List | [#206](https://leetcode.com/problems/reverse-linked-list/) | Easy |
| [Lec3.cpp](Lec3.cpp) | Middle of the Linked List | [#876](https://leetcode.com/problems/middle-of-the-linked-list/) | Easy |
| [Lec4.cpp](Lec4.cpp) | Linked List Cycle Detection & Start + Remove Cycle | [#141](https://leetcode.com/problems/linked-list-cycle/) / [#142](https://leetcode.com/problems/linked-list-cycle-ii/) | Easy / Medium |
| [Lec5.cpp](Lec5.cpp) | Merge Two Sorted Lists | [#21](https://leetcode.com/problems/merge-two-sorted-lists/) | Easy |
| [Lec6.cpp](Lec6.cpp) | Copy List with Random Pointer | [#138](https://leetcode.com/problems/copy-list-with-random-pointer/) | Medium |
| [Lec7.cpp](Lec7.cpp) | Doubly Linked List - Implementation | — | Concept |
| [Lec8.cpp](Lec8.cpp) | Circular Linked List - Implementation | — | Concept |
| [Lec9.cpp](Lec9.cpp) | Flatten a Multilevel Doubly Linked List | [#430](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/) | Medium |
| [Lec10.cpp](Lec10.cpp) | Reverse Nodes in k-Group | [#25](https://leetcode.com/problems/reverse-nodes-in-k-group/) | Hard |
| [Lec11.cpp](Lec11.cpp) | Swap Nodes in Pairs | [#24](https://leetcode.com/problems/swap-nodes-in-pairs/) | Medium |

---

## Detailed Notes

### Lec1 — Singly Linked List Implementation
Basic singly linked list built from scratch.

**Operations implemented:**
- `push_front(val)` — Insert at the beginning
- `push_back(val)` — Insert at the end
- `insert(val, pos)` — Insert at a given position
- `pop_front()` — Delete from the beginning
- `pop_back()` — Delete from the end

---

### Lec2 — Reverse Linked List (LC #206)
Iteratively reverses a singly linked list using three pointers (`prev`, `curr`, `next`).

**Approach:** Two-pointer / Iterative  
**Time:** O(n) | **Space:** O(1)

---

### Lec3 — Middle of the Linked List (LC #876)
Finds the middle node using the **slow and fast pointer** (tortoise & hare) technique.
- If two middle nodes exist, returns the **second** one.

**Approach:** Slow & Fast Pointer  
**Time:** O(n) | **Space:** O(1)

---

### Lec4 — Linked List Cycle (LC #141 & #142)
Three solutions covered in one file:

1. **Detect Cycle (LC #141):** Uses slow/fast pointers — if they meet, a cycle exists.
2. **Find Cycle Start (LC #142):** After detection, reset slow to head and move both one step at a time; they meet at the cycle's start node.
3. **Remove Cycle:** Extension of #142 — once the start is found, `prev->next = NULL` removes the cycle.

**Approach:** Floyd's Cycle Detection Algorithm  
**Time:** O(n) | **Space:** O(1)

---

### Lec5 — Merge Two Sorted Lists (LC #21)
Recursively merges two sorted linked lists into a single sorted list.

**Approach:** Recursion  
**Time:** O(n + m) | **Space:** O(n + m) (call stack)

---

### Lec6 — Copy List with Random Pointer (LC #138)
Creates a deep copy of a linked list where each node has a `next` and a `random` pointer.

**Approach:** HashMap (`unordered_map<Node*, Node*>`) to map old nodes to new nodes, then assign `random` pointers in a second pass.  
**Time:** O(n) | **Space:** O(n)

---

### Lec7 — Doubly Linked List Implementation
A doubly linked list (DLL) built from scratch with both `head` and `tail` pointers.

**Operations implemented:**
- `push_front(val)` — Insert at front, update `prev` pointer
- `push_back(val)` — Insert at back, update `prev` pointer
- `pop_front()` — Remove from front
- `pop_back()` — Remove from back
- `print()` — Display list as `a <=> b <=> ... <=> NULL`

---

### Lec8 — Circular Linked List Implementation
A circular singly linked list where the tail's `next` always points back to `head`.

**Operations implemented:**
- `insert_at_begin(val)` — Insert at front, update `tail->next`
- `insert_at_end(val)` — Insert at end, maintain circular link
- `delete_at_front()` — Remove head, update `tail->next`
- `delete_from_tail()` — Traverse to find new tail, update circular link
- `print()` — Display the circular list

---

### Lec9 — Flatten a Multilevel Doubly Linked List (LC #430)
Flattens a multilevel doubly linked list so that child lists are inserted between the current node and its next node.

**Approach:** Recursive DFS — for each node with a child, recursively flatten the child list, attach it after the current node, then find the tail to reconnect with the original `next`.  
**Time:** O(n) | **Space:** O(n) (call stack)

---

### Lec10 — Reverse Nodes in k-Group (LC #25)
Reverses every k consecutive nodes in a linked list. If fewer than k nodes remain, they are left as-is.

**Approach:** Recursion — check if k nodes exist, recursively process remaining list as `prevNode`, then reverse current k nodes pointing to `prevNode`.  
**Time:** O(n) | **Space:** O(n/k) (call stack)

---

### Lec11 — Swap Nodes in Pairs (LC #24)
Swaps every two adjacent nodes in a linked list without modifying node values.

**Approach:** Iterative — use `first`, `sec`, and `prev` pointers to swap pairs, updating head for the first pair.  
**Time:** O(n) | **Space:** O(1)

---

## Key Concepts & Techniques

| Technique | Used In |
|-----------|---------|
| Slow & Fast Pointer (Tortoise & Hare) | Lec3, Lec4 |
| Floyd's Cycle Detection | Lec4 |
| Two Pointer / Iterative Reversal | Lec2, Lec11 |
| Recursion on Linked List | Lec5, Lec9, Lec10 |
| HashMap for Node Mapping | Lec6 |
| Doubly Linked List with `prev` pointer | Lec7, Lec9 |
| Circular Linking (`tail->next = head`) | Lec8 |
