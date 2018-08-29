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

int * topoSort(vector<int> graph[], int N)
{
   static int* seq = new int[N];
   int k=0;
   stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    for (int i = 0; i < N; i++)
    if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack, graph);

    while (Stack.empty() == false)
        {
            seq[k++] = Stack.top();
            //cout<<Stack.top()<<"   ";
            Stack.pop();
        }
    for(int i=0; i<6;i++)cout<<seq[i]<<" ";
    return seq;

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
#endif // SUDO_PLACEMENT_ALGO_DS_H_INCLUDED
