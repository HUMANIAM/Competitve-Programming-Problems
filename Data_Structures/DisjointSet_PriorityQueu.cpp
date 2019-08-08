#include "DisjointSet_PriorityQueu.h"
/**Build Heap from array
**************************
*/
vector<Pair> swaps; // count Pairs

void printPairs(){
    cout << swaps.size() << endl;
    for(const auto& sw : swaps)
        cout << sw.i << ' ' << sw.j << endl;
}


/// sift down a node if one if its children has min value
static void siftDown(vector<int>& arr, int i, int sz){
    int minIndex = i;
    int leftChild = i*2 + 1;
    int rightChild = leftChild + 1;

    // if left child has smaller value make it the min index
    if(leftChild < sz && arr[leftChild] < arr[minIndex])
        minIndex = leftChild;

    // if right child has the smaller value make it the min index
    if(rightChild < sz && arr[rightChild] < arr[minIndex])
        minIndex = rightChild;

    if(minIndex == i) return;

    // Pair values and sift down again
    Pair(arr[i], arr[minIndex]);
    swaps.push_back({i, minIndex});
    siftDown(arr, minIndex, sz);
}


void buildHeap(vector<int>& arr){
    int sz = arr.size();

    // apply sift down for nodes in depth 1 to n/2
    for(int i=sz/2; i >= 0; i--){
        siftDown(arr, i, sz);
    }

    // print Pairs
    printPairs();
}


/**2- Parallel processing*/
///*************************
vector<Thread> jobs_threads;
vector<Thread> threads_PQ;

/// set the free time for all threads with zero at the beginning.
void init_threads_PQ(int n){
    for(int i=0; i<n; i++)
      threads_PQ.push_back({i, 0});
}


/// get the min thread from 2 threads. choose based on the Free time then index
int getMinThread(int i, int j){
    // if they have the same free time then return the one with smaller index
    if(threads_PQ[i].freeTime == threads_PQ[j].freeTime)
        if(threads_PQ[i].index < threads_PQ[j].index)   return i;
        else                                            return j;

    // if they have different free time then return the smaller on.
    if(threads_PQ[i].freeTime < threads_PQ[j].freeTime) return i;
    else                                                return j;
}


/// siftDown based on free time and index in equality case.
void siftDown_PQ(int i){
    static int sz = threads_PQ.size();
    int minThread = i;
    int leftChild = 2*i + 1;
    int rightChild = leftChild + 1;

    // from the children of i node choose the child with min free time if they have the same free time
    // then choose the one with smaller index say it is node j
    // if node j has the same free time as i then check if its rank is less than the i node if yes
    // sift i node down and j node up
    if(leftChild < sz)
        minThread = getMinThread(leftChild, minThread);

    if(rightChild < sz)
        minThread = getMinThread(minThread, rightChild);

    if(minThread == i) return;
    swap(threads_PQ[i], threads_PQ[minThread]);

    siftDown_PQ(minThread);
}


/// update the free time of a thread
void incrementPriorityQueue(int i, int val){
    threads_PQ[i].freeTime += val;
    siftDown_PQ(i);
}


/// assign jobs for threads that expected to be free soon
static void processJobs(vector<int>& jobs_ptime, int jobs, int threads){
    // process jobs one by one
    for(int job = 0; job < jobs; job++){
        // pick the threads that has the lowest index and also the closest one to be free
        jobs_threads.push_back(threads_PQ[0]);

        //update the free time of the selected thread
        incrementPriorityQueue(0, jobs_ptime[job]);
    }
}


///print assigned threads for jobs and their start time
void printThreads_jobs(){
    for(const auto& th : jobs_threads)
        cout << th.index << ' ' << th.freeTime << endl;
}


/// driver function of processing jobs
void parallelProcessing(){
    jobs_threads.clear();
    threads_PQ.clear();

    int n, m;
    cin >> n >> m;

    vector<int> jobsProcessingTime(m);

    // get jobs processing time
    for(int i=0; i<m; i++) cin >> jobsProcessingTime[i];

    // initialize the priority queue
    init_threads_PQ(n);

    // process jobs
    processJobs(jobsProcessingTime, m, n);

    //print pairs
    printThreads_jobs();

}

/**3- merge Tables
*/
vector<Table> tables;
vector<MergeOperation> mergeoperations;


int updateTables(int targetID, int sourceID){
    //update rows
    tables[sourceID].symLink_t = targetID;
    tables[targetID].rows_t += tables[sourceID].rows_t;
    tables[sourceID].rows_t = 0;

    //if they have the same rank then increment the rank of the targetID
      if(tables[targetID].rank_t == tables[sourceID].rank_t)
        tables[targetID].rank_t += 1;

    //return new no of rows after merging
    return tables[targetID].rows_t;
}


// find the set ID with path compression heuristic
int findID(int t){
    if(tables[t].symLink_t == t)
        return t;

    return tables[t].symLink_t = findID(tables[t].symLink_t);
}


// using the rank heuristic we merge tables
int unionTables(int t1, int t2){
    int tableID1 = findID(t1);
    int tableID2 = findID(t2);
    int newRows;

    // merge the tables in the same set does not change anything
    if(tableID1 == tableID2) return tables[tableID1].rows_t;

    // merge the one with lower rank under the one with higher rank
    if(tables[tableID1].rank_t < tables[tableID2].rank_t)
        newRows = updateTables(tableID2, tableID1);
    else
      newRows = updateTables(tableID1, tableID2);

    return newRows;
}


void executeMergeOperations(int maxRow){
    for(const auto& mergeOP : mergeoperations){
        int newRows = unionTables(mergeOP.destination, mergeOP.source);
        maxRow = max(maxRow, newRows);
        cout << maxRow << endl;
    }
}

//read input
int readData(){
    int maxRows = -1;
    int n, m, r;
    cin >> n >> m;

    // read rows
    for(int i=0; i < n; i++){
       cin >> r;
       tables.push_back({r, 0, i});
       maxRows = max(maxRows, r);
    }

    // read merge operations
    int d, s;
    for(int i=0; i < m; i++){
        cin >> d >> s;
        mergeoperations.push_back({d-1, s-1});
    }

    return maxRows;
}

void mergeTables(){
    // clear data storage
    mergeoperations.clear();
    tables.clear();

    // read data
    int maxRows = readData();

    // execute merge operations
    executeMergeOperations(maxRows);
    cout << "*************************\n";
}
