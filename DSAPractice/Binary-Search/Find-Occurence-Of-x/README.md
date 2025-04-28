📚 Problem: Find First and Last Occurrence of a Number in a Sorted Array
Problem Statement
You are given a sorted array containing N integers and an integer X.
Your task is to find the first and last occurrence of X in the given array.

If X exists, output its first and last index.

If X does not exist in the array, output {-1, -1}.

Note: Array indexing is 0-based.

Input
An integer N — the size of the array.

An array arr of N integers sorted in non-decreasing order.

An integer X — the element whose first and last occurrences need to be found.

Output
A pair of integers representing the first and last index of X.

If X is not present, output {-1, -1}.

Constraints
1 ≤ N ≤ 10^5

-10^9 ≤ arr[i], X ≤ 10^9 (for all 0 ≤ i < N)

Example
Input

Copy
Edit
6
3 4 4 7 8 10
4
Output

Copy
Edit
1 2
Explanation
Element 4 first appears at index 1 and last appears at index 2.

Input

Copy
Edit
5
2 4 6 8 10
5
Output

diff
Copy
Edit
-1 -1
Explanation
Element 5 does not appear in the array.