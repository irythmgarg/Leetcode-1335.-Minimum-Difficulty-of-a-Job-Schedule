# Leetcode-1335.-Minimum-Difficulty-of-a-Job-Schedule
# 💼 Minimum Difficulty of a Job Schedule

This README explains **two approaches** to solve the problem of finding the **minimum total difficulty** of a job schedule given `d` days and a list of job difficulties.

---

## 📘 Problem Statement

Given an array `jobDifficulty[]` and an integer `d`, schedule the jobs over `d` days such that:

* You **must schedule at least one job per day**.
* Jobs must be scheduled in **order**.
* The difficulty of a day is the **maximum difficulty** among the jobs scheduled on that day.
* Return the **minimum total difficulty** across all days.

If it is **not possible** to schedule all jobs over `d` days, return `-1`.

---

## 🧪 Example

```txt
Input: jobDifficulty = [6, 5, 4, 3, 2, 1], d = 2
Output: 7
Explanation:
Day 1: jobs = [6,5,4] -> max = 6
Day 2: jobs = [3,2,1] -> max = 3
Total = 6 + 3 = 9
But a better partition is:
Day 1: jobs = [6] -> max = 6
Day 2: jobs = [5,4,3,2,1] -> max = 5
Total = 6 + 5 = 11
Best possible: [6,5,4] and [3,2,1] => Total = 7 ✅
```

---

## ✅ Approach 1: Pure Recursive Solution (No DP)

### 🔍 Idea

* Try every possible split of jobs for each day.
* For each split, recursively compute the minimum difficulty of remaining jobs.

### 🧠 How It Works

1. Start from index `i = 0`, `d` days remaining.
2. Assign jobs from `i` to `j` to the current day.
3. Track the max difficulty in this range.
4. Recursively solve for the rest.
5. Return the **minimum** sum of all configurations.

### 📦 Time & Space Complexity

* **Time:** Exponential (Overlapping subproblems).
* **Space:** O(n) recursion stack.

### ❗ Why It Is Inefficient

* **Overlapping Subproblems**: Same `(i, d)` pairs are computed multiple times.
* Leads to **TLE** (Time Limit Exceeded) on larger inputs.

---

## ✅ Approach 2: Top-down DP with Memoization

### 🔍 Idea

* Same recursive logic as above.
* But we store results for `(i, d)` in a memoization table (`dp[i][d]`).

### 🧠 How It Works

1. If already computed for `(i, d)`, return `dp[i][d]`.
2. Try all splits from current index.
3. Store and reuse results to avoid recomputation.

### 📦 Time & Space Complexity

* **Time:** O(n \* d) — every state `(i, d)` computed once.
* **Space:** O(n \* d) for `dp` + O(n) recursion stack.

### ✅ Why It Works

* Drastically reduces the time by avoiding recalculations.
* Efficient and optimal for large input sizes.

---

## ⏱ Complexities Summary

| Approach          | Time Complexity | Space Complexity |
| ----------------- | --------------- | ---------------- |
| Recursive (No DP) | Exponential     | O(n)             |
| DP + Memoization  | O(n \* d)       | O(n \* d)        |

---

## 👨‍💻 Author

**Name:** Ridham Garg
**Roll No:** 102203014
**Institute:** Thapar University, Patiala

---

## 🏁 Conclusion

* Use the **DP approach** for optimal performance ✅
* Recursive approach is helpful to understand the core logic but is **not scalable** ❌
* Always check for base cases and edge conditions (e.g., not enough jobs for days)

---

Happy Coding! 🚀✨
