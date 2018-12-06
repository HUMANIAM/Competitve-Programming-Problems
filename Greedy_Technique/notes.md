##										 Greedy Algorithms 

- the main Idea behind the greedy technique is making sure that any move will be safe that means this move 	will reach you to an optimal solution

- how to make you choice is safe you need to do some computation like sort the input, normalize it, do 	    something that helps you to make you choices are safe. if you prove that your move can't be safe then 	you can try another technique like dp, backtracking, local search, sat solver ,........

- the next problems are training on the greedy technique to master where exactly it can be successful and where it can be failure. I need to find the main feature of the greedy technique.

- I notice that in most problems, greedy algorithm sort objects in a specific order to start make greedy choices. sometimes, we don't need any preprocessing and start greedy choices immediately. 

#### general steps on greedy problems :

- you reduce the main problem to other problem that you can use the same technique (greed) to solve it
	in the first example below you can say with GreatestNumber(9, 1, 2, 3) that 
	soution = 9 + GreatestNumber(1, 2, 3) GreatestNumber is a new subproblem and you can solve it with the 
	same technique

- Greedy Choice is called (Save move) if and only if there is an optimal solution consistent with this 
	first move and not all first moves are safe where often greedy moves are not safe
	so you must follow these steps to make sure your solution is correct
	* make greedy move  * proof it is safe  * reduce to subproblem  * solve the subproblem

### Examples:
- __Find max number from list of digits__: find max digit in the list remove it from the list then append 												it the number

- __car fueling__: 
**Input**: A car which can travel at most L kilometers with full tank, a source
     				           point A, a destination point B and n gas stations at distances
						      x1 ≤ x2 ≤ x3 ≤ · · · ≤ xn in kilometers from A along the path from A to B

				 	**output** : The minimum number of refills to get from A to B, besides refill at A

- __Group children__ : 

Many children came to a celebration. Organize them into the minimum possible 							number of groups such that the age of any two children in the same group diffeer by at most one year.

__efficient algorithm__ :

 you can reformulate the to anthor problem whicht will be (find the minimum number of segments of unit length to cover all points in a line) put the children into line then sort them and apply the constraint to group them this will take O(nlog(n)) for sorting and O(n) for the greedy algorithm.

- __Fractional knapsack__ : 

**Input**: Weights w1, . .  wn and values v1, . . , vn of n items; capacity W 
**Output**: The maximum total value of fractions of items that fit into a bag of capacity W .

**intuitive solution** : 
sort Vi/Wi and select in a greedy way ther greater one by the greater one. complexity time is O(nlog(n))







