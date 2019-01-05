# 									Divide and conquer

##A More General Divide-and-Conquer Approach

-  **Divide** : divide the given problem into subprobelms (ideally of approximately equall size)
-  **Conquer**: solve each subproblem (directly or recursively)
-  **Combine**: combine the solution of subproblems into global solution


## Examples

- **Merge sort** : 
you divide the array into smaller sub arrays and sort them then you combine the sorted sub array with other sorted sub array. in average case this will take O(nlog(n))

- **Polynomial Multiplication**
you are given two vectors presents the coefficients of two equations A(x), B(x). size of every one of them is n. A(x) = \sum_{i=0}^{n} a_i B(x) = \sum_{i=0}^{n} b_i C(x) = \sum_{k=0}^{n^2} c_k 
and C_k = \sum_{i=0}^{k} a_i.b_k-i. This is a brute force solution and will take time \theta(n^2) of multiplication and \theta(n^2) of addition so the complexity time will be  \theta(n^2).

can divide and conquer techinque do better?

