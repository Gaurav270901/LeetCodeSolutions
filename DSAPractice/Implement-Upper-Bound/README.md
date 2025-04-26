Problem Statement: Find Upper Bound
You are given a sorted array of N integers and an integer X.
Your task is to find the index of the first element that is strictly greater than X.

If there is no element greater than X, return N (the size of the array).

🔹 Definition:
The upper bound of X is the smallest index ind such that arr[ind] > X.

Input:
An integer N — the number of elements in the array.

A sorted array of N integers — arr[0], arr[1], ..., arr[N-1].

An integer X — the target value.

Output:
A single integer — the index of the upper bound of X in the array (or N if no such index exists).

Example 1:
Input:


N = 6
arr = [2, 4, 6, 8, 10, 12]
X = 6
Output:


3
Explanation:
arr[3] = 8 is the first element greater than 6.

Example 2:
Input:


N = 5
arr = [1, 3, 3, 5, 7]
X = 3
Output:


3
Explanation:
arr[3] = 5 is the first element greater than 3.

Constraints:
1 <= N <= 10^5

-10^9 <= arr[i], X <= 10^9

arr is sorted in non-decreasing order.

