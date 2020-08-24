LONGEST ARITHMETIC PROGRESSION
Given a set of numbers, find the length of the longest arithmetic progression (LLAP) in it.
Examples:
Input:
1, 7, 10, 15, 27, 29
Output:
3
Explanation:
Longest AP is {1, 15, 29}

Input:
1, 3, 5, 10, 15, 29, 43
Output:
4
Explanation:
Longest AP is:
15 29 43
1 15 29
5 10 15
1 3 5


Approach:

We look for 3 elements in the AP and if we find such elements, we will increment the count. Hence for these set of element, there must exist the two elements that form an AP such that set[i] + set[k] = 2*set[j], j being the middle element.

1. Initialize i as j-1 and k as j+1
2. Do following while i >= 0 and j <= n+1
If set[i] + set[k] is equal to 2*set[j], then we increment the count and store the operation on
L[i][j] with incremented value of L[j][k] (L[j][k] + 1)
 
If set[i] + set[k] > 2*set[j], then decrement i (do i--)
Else if set[i] + set[k] < 2*set [j], then increment k (do k++)
	
