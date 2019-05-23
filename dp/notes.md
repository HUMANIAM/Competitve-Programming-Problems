#									Dynamic programming

`DP : is an algorithm design techique that can improve the efficiency of any inherently recursive algorithm that repeatedly re-solves the same subproblems.
Using dynamic programming requires two steps:
1- You find a recursive solution to a problem where subproblems are redundantly solved many times.
2- Optimize the recursive algorithm to eliminate re-solving subproblems. The resulting algorithm may be recursive or iterative. The iterative form is commonly referred to by the term dynamic programming`

`There are are 2 techiques to reserve results of recursively subproblems
1- memoization to avoid redundant computation (saving results of subproblems)
2- tabulation the value of each subproblem must be stored in the table. we reverse the solutins 	to the subproblems from the starting point, and implement this by a simple loop.
there is no mechanical way to get from the orginal recursive form to the dynamic programming form.`

## Examples
* Computing fibonacci numbers
* Knapsack problem
