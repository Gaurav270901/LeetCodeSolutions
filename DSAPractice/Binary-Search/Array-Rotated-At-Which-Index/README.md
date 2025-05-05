🔄 Problem: Find the Number of Times a Sorted Array is Rotated
Problem Statement
You are given an array arr of size N, which is sorted in ascending order and then rotated between 1 to N times. The rotation means that some prefix of the array has been moved to the end (as in circular rotation). Your task is to determine the number of times the sorted array has been rotated.

⚠️ The array contains distinct elements.

Input
An integer N — the size of the array.

An array arr of N distinct integers, which was originally sorted in ascending order but is now rotated.

Output
A single integer representing the number of times the array has been rotated.

This is equal to the index of the minimum element in the rotated array.

Constraints
1 ≤ N ≤ 10^5

-10^9 ≤ arr[i] ≤ 10^9

Example
Input

ini
Copy
Edit
N = 5  
arr = [4, 5, 1, 2, 3]
Output

Copy
Edit
2
Explanation
The original array was [1, 2, 3, 4, 5].
After 2 rotations, it became [4, 5, 1, 2, 3].
The minimum element is 1 at index 2, which indicates the array was rotated 2 times.

Observation
The number of rotations is equal to the index of the minimum element in the rotated array.

Follow-Up
Can you solve this in O(log N) time using Binary Search?

💡 Hint: Modify the binary search used in the “Find Minimum in Rotated Sorted Array” problem to return the index instead of just the value.

