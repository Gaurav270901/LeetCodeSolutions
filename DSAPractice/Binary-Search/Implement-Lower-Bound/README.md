Implement Lower Bound

Mark as Completed

263


Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

Pre-requisite: Binary Search algorithm

Examples
Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Solution:
In the preceding article, we comprehensively explored the implementation of the Binary Search algorithm. 

The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

In this article, we will learn how to implement the lower bound algorithm using a slight modification of the Binary Search algorithm. 

Let’s start.

What is Lower Bound?
The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.