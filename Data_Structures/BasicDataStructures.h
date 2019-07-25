#ifndef BASICDATASTRUCTURES_H_INCLUDED
#define BASICDATASTRUCTURES_H_INCLUDED
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
#include <map>
using namespace std;

typedef vector<vector<int> > INt_MATRIX;

/**Arrays
1- contiguous area of memory consist of equal-size elements indexed by contiguous integers
2- constant time access
*/

/**single linked list
1- every node has data and one pointer to the previous element
2- allocated memory scattered in the heap.
*/

/** Doubly linked list
1- every node has data and 2 pointers one for the next node and one for the previous node
2- allocated memory scattered in the heap
*/


/** Stack
1- works according to LIFO policy
2- APPS like balanced brackets,
3- you can implement it using arrays or linked list
4- each operation O(1)
*/


/** Queue
1- works according to FIFO policy
2- can be implemented using arrays and linkedList has head and tail pointers
3- each operation O(1)
*/

/**Trees
1- APPS:::  Syntax Tree for a Sentence, Animal kingdom, Geography hierarchy and binary search tree
2- we represent every node with data and pointers to its children and also may be its parents


Walking a tree
*************
1- Depth first search (DFS): completely traverse one subtree before traversing sibling subtree
---------------------------
2- Breadth first search (BFS): traverse the tree level by level
-----------------------------

processing during traversing in DFS mode:
*****************************
1- In Order Traversal: sequence of processing left > the node > right
---------------------
2- Pre Order Traversal: sequence of processing the node > left > right
----------------------
3- Post Order Traversal: sequence of processing left > right > the node
---------------------



Types of Trees
**************

1- binary search tree: it is a tree where every node has maximum 2 children and all the nodes in the RHS of the
---------------------  current node are greater than the current node and all the data in the LHS of the current
node are less than the data in the current node. so searching will be O(log(n)). In fact you can represent the bst
data structure with array where the node i has LHS child 2i + 1 and RHS child LHS child + 1.

2- Forest: is a collection of trees
---------

3- Balanced binary tree: AVL, SPLAY Trees, black red trees
-----------------------
*/


/// PROBLEMS
/** 1- Check brackets in the code. If all brackets match print SUCCESS else print the first bracket does not
match
*/

const string openBrackets  = "({[";
const string closeBrackets = ")}]";

typedef struct Bracket{
    int index;
    char bracket;
    Bracket(int i, char br): index(i), bracket(br)
    {}
} Bracket;

// return the first unmatched bracket if brackets match return -1
int matchBrackets(const string&);


/**Tree Height
*/
static void readTree();
int treeHeight();


/**Network packet processing simulation
Queue Application
*/
typedef struct Packet{
    int arrival_time, processing_time, startProcessing_time;
    Packet(int arrTime, int procTime){
        arrival_time = arrTime;
        processing_time = procTime;
        startProcessing_time = -1;
    }
} Packet;

void packetProcessingSimulation();

#endif // BASICDATASTRUCTURES_H_INCLUDED
