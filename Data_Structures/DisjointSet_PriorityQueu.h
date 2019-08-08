#ifndef DISJOINTSET_PRIORITYQUEU_H_INCLUDED
#define DISJOINTSET_PRIORITYQUEU_H_INCLUDED
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/** DisJoint Set
________________
disjoint set is a data structure where there is no 2 sets has any shared element so it is called disjoint
every set has number of elements on of them is the group identifier. If 2 elements have the same belongs to
same identifier then they locate in the same set. operations[find(x), makeSet(x), union(x, y)]
Applications:
************
1- reachability search problems
2- building a network

implementation
*************
* linked list : O(1) for merge, O(n) for find
* array:        O(n) for merge, O(1) for find
* tree:         O(log(n)) for merge, O(log(n)) for find (using rank heuristic)
* tree:         O(log*(n)) = O(1) for practical n for all operations (using rank heuristic and path compression)

-**- in tree we hang tree with small height under the tree with large height (union by rank heuristic)
-**- iterated logarithm log*(n) : is the number of times you need to execute logarithm on N to reach 1
*/

/** Priority Queue
* pQ is implemented using binary min-heap, or binary max-heap
* binary max heap: is a binary tree with property "every node has priority at least its children"
* using sift up and sift down we can emphasis the binary heap property.
* heap sort is using max-heap to sort the array with O(n*log(n)) by first convert the array into the heap
  ********* then swap values from beginning to the end of the array.
* Operations: extractMax, insert


HeapSort is used for external sort when you need to sort huge files that don’t fit into memory of your
computer.
*/

/**Problems
*/

/**1- Build Heap From Array*/
typedef struct Pair{int i, j; Pair(int ii, int jj): i(ii), j(jj){}} Pair;

static void siftDown(vector<int>&, int, int);
void buildHeap(vector<int>&);

/**2- Parallel processing*/
typedef struct Thread{int index, freeTime; Thread(int i, int ft): index(i), freeTime(ft){}} Thread;
void parallelProcessing();


/**3- Merge Tables*/
// merge tables using rank heuristic for merging and path compression for finding.
// every node has symbolic link may be for other table or for itself every, and its number of rows
// and its rank
typedef struct Table{
    int rows_t, rank_t, symLink_t;
    Table(int r, int ra, int sl): rows_t(r), rank_t(ra), symLink_t(sl)
    {}

} Table;

typedef struct MergeOperation{
    int destination, source;
    MergeOperation(int d, int s): destination(d), source(s)
    {}
} MergeOperation;

void mergeTables();
#endif // DISJOINTSET_PRIORITYQUEU_H_INCLUDED
