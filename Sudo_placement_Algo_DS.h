#ifndef SUDO_PLACEMENT_ALGO_DS_H_INCLUDED
#define SUDO_PLACEMENT_ALGO_DS_H_INCLUDED
#include <stack>
#include<string>
#include <vector>
#include <map>
#include <list>
#include <set>
using namespace std;
typedef long long ll;
#define pb push_back
#define VecINT vector<int>
#define SETINT set<int>
#define MAPINT map<int, int>
#define STINT stack<int>

/*                          //find the closest palindrome number//              */
/*                          --------------------------------------              */
/* Description : Given a number N. our task is to find the closest Palindrome number whose absolute difference with given number is minimum.*/

ll stoi(string s){
    ll res = 0;
    for(int i=0; i<s.length(); i++)
        res = res*10 + (s[i]-'0');
    return res;
}

string closestPalindrome(string& s){
    string l,g;
    l=s;
	int len = s.length();

	for(int i=0;i<len/2; i++)
        l[len-1-i] = l[i];

    g = l;
    if(s == l)  //they are the same
	{
	    return s;
	}
	else if(stoi(l) < stoi(s))  //find the greater palindrome by add one to the pair center
	{
	    int c=0;
	    int x = len/2;
	    if(len%2 == 0) x--;

	    while(g[x-c] == '9')
            g[x-c] = g[len - 1-x+(c++)] = '0';

	    g[len-1-x+c]= ++g[x-c];

	}
	else if(stoi(g) > stoi(s))   //find the less palindrome by add one to the pair center
	{
	     int c=0, x;
	    x = len/2;
	    if(len%2 == 0) x--;

	    while(l[x-c] == '0')
            l[x-c] = l[len - 1-x+(c++)] = '9';

	    l[len-1-x+c]= --l[x-c];

	}

	if(stoi(g)-stoi(s) < stoi(s)-stoi(l))
	    return g;
	else
	    return l;

}



/*                                  //Topological sort //            */
// Constraints :* at every node its parents must be explored before
//               * In topological sorting, we need to print a vertex before its adjacent vertice
//              * O(V+E) where visiting every single V and check every single edge
//              * BFS always returns an optimal answer, but this is not guaranteed for DFS.


//if any child refers to its parent that creates a cycle
//solution by stack and dfs method
class Graph
{
private:
	int V; // No. of vertices'
	list<int> *adj;

	// A recursive function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
    {
        // Mark the current node as visited.
        visited[v] = true;

        // Recur for all the vertices adjacent to this vertex
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                topologicalSortUtil(*i, visited, Stack);
        Stack.push(v);
    }
public:
        Graph(int V)        // Constructor
        {
            this->V = V;
            adj = new list<int>[V];
        }

	// function to add an edge to graph
	void addEdge(int v, int w)
    {
        adj[v].push_back(w); // Add w to v’s list.
    }

	// prints a Topological Sort of the complete graph
	void topologicalSort()
    {
        stack<int> Stack;

        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Call the recursive helper function to store Topological
        // Sort starting from all vertices one by one
        for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

        // Print contents of stack
        while (Stack.empty() == false)
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }

};


bool cycle(VecINT graph[],  int n, set<int> vs, set<int> parents){
    if(vs.find(n) == vs.end()){
        vs.insert(n);
        parents.insert(n);

        for(int i=0; i<graph[n].size(); i++){
            int n0 = graph[n][i];
            if(vs.find(n0) == vs.end() && cycle(graph, n0, vs, parents)) return true;
            else if(parents.find(n0) != parents.end())  return true;
        }
    }
    parents.erase(n);
    return false;
}

void createTopTable(VecINT graph[], int N, map<int, int>& mp, STINT& st){

    for(int i=0; i<N; i++) mp[i] = 0;

    for(int i=0; i<N; i++)
        for(int j=0; j<graph[i].size(); j++)
            mp[graph[i][j]]++;

    for(int i=0; i<N; i++)
        if(mp[i]==0)
            st.push(i);
}

/*                                  //Alien Dictionary//             */
/*                                    -----------------              */
/*Description: Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary the task is to
  ------------ a string denoting the order of characters in the language.complete the function which returns

  solution: this problem is training on topological sort the condition is the graph must be DAG
  --------  then select nodes that has no parents and start on of them. after that we find the sequence

  Type : Topological sort

*/

bool hasCircle(map<int, vector<int> > &mp, int u, set<int>& vs, set<int>& st){
    if(vs.find(u) == vs.end()){
        vs.insert(u);           //visited list used not to discover nodes that already discovered before
        st.insert(u);           //where the graph is unidirectional we need to use list to the current explored nodes of the current node

        for(int i = 0; i < mp[u].size(); i++){
            int v = mp[u][i];

            //dfs for check if there is a cycle
            if(vs.find(v) == vs.end() && hasCircle(mp, v, vs, st)) return true;
            else if(st.find(v) != st.end()) return true;
        }
    }
    st.erase(u);
    return false;
}

void topo(map<int, vector<int> > &mp, stack<int>& st, int u, set<int> &vs){
    if(vs.find(u) != vs.end()) return;
    vs.insert(u);
    for(int i = 0; i < mp[u].size(); i++)
        topo(mp, st, mp[u][i], vs);
    st.push(u);
}

string printOrder(string dict[], int N, int k)
{
   //create the map
   map<int, vector<int> > mp;
   for(int i = 0; i < N; i++){
       string s = dict[i];
       for(int j = 0; j < s.size(); j++){
           char c = s[j];
           if(mp.find(c) == mp.end())
               mp.insert(pair<int, vector<int> >(c, vector<int>()));
       }
   }

   //create graph of letters 'letter' : [connected letters]
   for(int i = 0; i < N - 1; i++){
       string s1 = dict[i], s2 = dict[i + 1];
       for(int j = 0; j < min(s1.size(), s2.size()); j++)
           if(s1[j] != s2[j]){
               mp[s1[j]].pb(s2[j]);
               break;
           }
   }

   //check there is no cycle
   set<int> vs; set<int> rec;
   for(auto it = mp.begin(); it != mp.end(); it++){
       if(hasCircle(mp, it->first, vs, rec)){
           return "";
       }
   }

   //topology sort
   vs.clear();
   stack<int> st;
  for(auto it = mp.begin(); it != mp.end(); it++){
      int u = it->first;
      topo(mp, st, u, vs);
  }
  string rs = "";
  while(!st.empty()){
      rs += st.top();
      st.pop();
  }
   return rs;
}

/*                              //Doctor strange
                                    ------------
Description: Kamar-taj is a place where "The Acient One" trains people to protect earth from other dimensions.
----------- The earth is protected by 'n' sanctums, destroying any of it will lead to invasion on earth.
            The sanctums are connected by 'm' bridges.
            Now , you being on dormammu's side , want to finds no of sanctum destroying which will disconnect the sanctums.

*/

#define NIL -1


// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
	void APUtil(int v, bool visited[], int disc[], int low[],
				int parent[], bool ap[]);
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void AP(); // prints articulation points
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}

void Graph::APUtil(int u, bool visited[], int disc[],
									int low[], int parent[], bool ap[])
{
	// A static variable is used for simplicity, we can avoid use of static
	// variable by passing a pointer.
	static int time = 0;

	// Count of children in DFS Tree
	int children = 0;

	// Mark the current node as visited
	visited[u] = true;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;

	// Go through all vertices aadjacent to this
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // v is current adjacent of u

		// If v is not visited yet, then make it a child of u
		// in DFS tree and recur for it
		if (!visited[v])
		{
			children++;
			parent[v] = u;
			APUtil(v, visited, disc, low, parent, ap);

			// Check if the subtree rooted with v has a connection to
			// one of the ancestors of u
			//low[u] = min(low[u], low[v]);

			// u is an articulation point in following cases

			// (1) u is root of DFS tree and has two or more chilren.
			if (parent[u] == NIL && children > 1)
			ap[u] = true;

			// (2) If u is not root and low value of one of its child is more
			// than discovery value of u.
			if (parent[u] != NIL && low[v] > disc[u])
			ap[u] = true;
		}

		// Update low value of u for parent function calls.
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

// The function to do DFS traversal. It uses recursive function APUtil()
void Graph::AP()
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	bool *ap = new bool[V]; // To store articulation points

	// Initialize parent and visited, and ap(articulation point) arrays
	for (int i = 0; i < V; i++)
	{
		parent[i] = NIL;
		visited[i] = false;
		ap[i] = false;
	}

	// Call the recursive helper function to find articulation points
	// in DFS tree rooted with vertex 'i'
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			APUtil(i, visited, disc, low, parent, ap);

	// Now ap[] contains articulation points, print them
	int s=0;
	for (int i = 0; i < V; i++)
		if (ap[i] == true)
			s++;
	cout<<s<<endl;
}


//anther solution with more time complexity

void dfs(vector<int> graph[], int n, set<int>& vs, int N){
        vs.insert(n);

        for(auto it=graph[n].begin(); it<graph[n].end(); it++){
            if(vs.find(*it) == vs.end()){
                dfs(graph, *it, vs, N);
                break;
            }
        }
}

int findMaxDesSanctums(vector<int> graph[], int N){
    int coun = 0;

    for(int n=0; n<N; n++){
        set<int> visited;
        visited.insert(n);

        if(graph[n].size() > 0)
            dfs(graph, graph[n][0], visited, N);

        if(visited.size()!=N) coun++;
    }
    return coun;
}


/*                      kill the captain of America
                        ---------------------------
Description:    Captain America is hiding from Thanos in a maze full of rooms.
----------      The maze is designed in such a way that the room, within it, leads to another room via gate.
                Captain America is hiding only in those rooms which are accessible directly/indirectly through every other room in the maze.
                Further provided that, the movement from one room (R1) to another room (R2) is one way(unidirectional) only .
                Now, you being on Thanos side, want to kill Captain America.
------------

*/
//ma : is transpose graph
//am : is the actual graph
void dfs(unordered_map<ll,vector<ll>>&ma ,vector<bool> &visited,ll source)
{
    visited[source]=true;
    for(ll adj : ma[source])
    {
        if(!visited[adj])
            dfs(ma,visited ,adj);
    }
}

ll kosaraju(ll n ,unordered_map<ll,vector<ll>>&ma,unordered_map<ll,vector<ll>>&am)
{
    vector<bool> visited (n);
    ll mother =1;
    for(ll i=1;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(ma,visited,i);
            mother = i;
        }
    }

    fill(all(visited),false);
    dfs(ma,visited,mother);
    if(count(all(visited),true)!=n)
        return 0;
    fill(all(visited),false);
    dfs(am,visited,mother);
    return count(all(visited),true);
}


/*                  largest number of other numbers  */
//                  ----------------------------------
int compare(int x, int y){
    string n1 = to_string(x);
    string n2 = to_string(y);
    return (n1+n2 >= n2+n1)? 1 : 0;
}

void createNum(vector<int>& nums){
    sort(nums.begin(), nums.end(), compare);
}



/*                  sort component according to frequencies      */
//                  ---------------------------------------
//note : If frequencies of two elements are same, print them in increasing order.
//first solution
void printmp(map<int, int>& mp){
    map<int, int>::iterator mit;

    while(true){
        int maxv = 0;
       for(auto it = mp.begin(); it!=mp.end(); it++){
        if(it->second > maxv){
            mit = it;
            maxv = it->second;
        }
    }
    //if all component is checked then break
    if(maxv == 0) break;

    for(int i=0; i<mit->second; i++)
        cout<<mit->first<<' ';
    mit->second = INT_MIN;

    }
}

//second solution
template<typename T1,typename T2>
class Comparator {
public:
	bool operator ()(const std::pair<T1, T2> &a, const std::pair<T1, T2> &b) const {
		return a.second > b.second;
	}
};

class Solution {
public:
    string frequencySort(string str) {
        std::map<char, int> mp;
        std::string res;
        for (auto c : str) {
            mp[c]++;
        }

        std::vector<std::pair<char, int>> mapCopy(mp.begin(),mp.end());
        sort(mapCopy.begin(),mapCopy.end(),Comparator<char,int>());

        for (auto it : mapCopy) {
            for (int i = 0; i < it.second; i++) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};


/*                                            spiral traversal of matrix            */
//                                            ---------------------------

void spiral(int a[4][4],int m,int n)
{

    int i, k = 0, l = 0;
    //k is the top row
    //l is the left col
    //n is the right col
    //m is the bottom row

    while (k < m && l < n){
        //print the top row
        for (i = l; i < n; ++i)
            cout<<a[k][i]<<' ';
        k++;

       //print the right col
        for (i = k; i < m; ++i)
            cout<<a[i][n-1]<<' ';
        n--;

        //print the bottom row
        for (i = n-1; i >= l; --i)
            cout<<a[m-1][i]<<' ';
        m--;

        //print the left col
        for (i = m-1; i >= k; --i)
            cout<<a[i][l]<<' ';
        l++;
    }
}


/*                                  find the number of subsequence has multiplication less than K       */
//                                  -------------------------------------------------------------
int findSeqLessK(int a[], int n, ll k)
{
    int coun=0;
    ll m = 1;

    for(int j=0, i=0; i<n; i++){
        if(j<i) j=i;
        while(j<n && m*a[j]>0 && m*a[j]<k) m*=a[j++];
        coun += j-i;
        if(j>i) m/=a[i];
    }
    return coun;
}

/*                                      Coin Exchange      */
/*                                  -----------------------
Description : you have set of coins and want to find the number of ways to change N value with these coins
--------
*/

//first solution:
int count( int S[], int m, int n )
{
    //if n = 0 don't include any coins
    if (n == 0)
        return 1;

    //n<0 no solution
    if (n < 0)
        return 0;

    //set is empty you can change coins with n>0
    if (m <=0 && n >= 1)
        return 0;

    //C({a0, a1, ...., an}, N) = c({a0, a1, ......., an}, N-an)+c({a0, a1, ......., an-1}, N);
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

//second solution
int count( int S[], int m, int n )
{
    int i, j, x, y;

    // We need n+1 rows as the table is constructed
    // in bottom up manner using the base case 0
    // value case (n = 0)
    int table[n+1][m];

    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;

    // Fill rest of the table entries in bottom
    // up manner
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}

/*                          make 2 strings anagram
/*                          ---------------------
Description:   you have 2 strings and want to make them anagram you can do that remove chars not in s1 but in s2 and vice versa we need to make the 2 strings
-----------    have the same chars in any order
*/
int remAnagram(string str1, string str2)
{
    int coun = 0;
    map<char, int> mp1, mp2;
    for(size_t i=0; i<str1.length(); i++)
        if(mp1.find(str1[i]) == mp1.end()) mp1[str1[i]] = 1;
        else mp1[str1[i]]++;

    for(size_t i=0; i<str2.length(); i++)
        if(mp2.find(str2[i]) == mp2.end()) mp2[str2[i]] = 1;
        else mp2[str2[i]]++;
    //count characters that we need to remove from the two strings
    for(auto it=mp1.begin(); it!=mp1.end(); it++)
        if(mp2.find(it->first) == mp2.end())
            coun+=it->second;
        else{
            coun += abs(it->second - mp2[it->first]);
        }

    for(auto it=mp2.begin(); it!=mp2.end(); it++)
        if(mp1.find(it->first) == mp1.end())
            coun+=it->second;

    return coun;
}

/*                                          maximum bike speed    */
/*                                          -------------------
Description: we have N bikes and every bike has speed vi and acceleration ai we need to know after what hours the total speed of bikes that
------------ exceed L speed will be greater than M speed

solution : binary search algorith
--------
*/
typedef struct biker
{
    long long sp;
    long long ac;
}biker;

int helper(biker arr[],int t)
{
    long long temp=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i].sp+arr[i].ac*t>=l)
        temp+=arr[i].sp+arr[i].ac*t;

        if(temp>=m)
        return 1;
    }
    return 0;
}
int MinHours(){
    ll n, m, l;
    cin>>n>>m>>l;
	biker arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i].sp>>arr[i].ac;

	int lo=0;
	int hi=INT_MAX;

	while(lo<hi)
	{
	    int mid=lo+(hi-lo)/2;
	    if(helper(arr,mid))
	    hi=mid;
	    else
	    lo=mid+1;
	 }

	cout<<lo<<endl;
}

/*                                  MAZE
Description:                       ----
-----------
find how many paths and the longest path
*/

void solveMaze(int mat[1000][1000], int n){
    path[0][0] = mat[0][0];
    ways[0][0] = 1;

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            if(ways[i][j]==0)
                continue;
            if(mat[i][j]%2==1)
            {
                ways[i][j+1] = (ways[i][j]+ways[i][j+1])%rem;
                path[i][j+1] = max(path[i][j]+mat[i][j+1],path[i][j+1]);
            }
            if(mat[i][j]>=2)
            {
                ways[i+1][j] = (ways[i][j]+ways[i+1][j])%rem;
                path[i+1][j] = max(path[i][j]+mat[i+1][j],path[i+1][j]);
            }
        }
        cout<<ways[n-1][n-1]<<' '<<path[n-1][n-1]<<'\n';
    }
}

#endif // SUDO_PLACEMENT_ALGO_DS_H_INCLUDED

