#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
#define P 1000000007
#define X 263
typedef unsigned long long ull;
using namespace std;

/**Hashing is all about mapping an object to another objects
* student Id > student name
* file Name > file Location
* object1 > object2
* Faster in retrieving, updating so it used in indexing and also use less memory so you don't need to have an
array with size 2^32 to to log their number of access to specific web service. You can use hash table to reduce
memory size
* Techniques to implement hash table
**********************************
1- chaining technique: used to implement hash table and avoiding collisions. using array of lists
-------------------- where index is the hashed value and in every entry we store the (k, v).
time complexity: O(C + 1)
memory complexity: O(m + n) where n no of objects in the table and m is the size of the table
*/

/** we use hashing for reducing the data storage used by our data. and also update and search in our data
storage quickly. It is a process of mapping where you map your value with hash function and m variable.
*/


/**Phone book problem
*/
struct Query {
    string type, name;
    int number;
};

class PhoneBook{
private:
    map<int, string> phone_book;
public:
    // add number
    void add_number(string, int);

    // delete number
    void delete_number(int);

    // find number
    string find_number(int);
};


/**Hash Table using chaining schema
*/
class HashTable{
private:
    vector<list<string> > hashtable;
    int m;

    //hash name
    int hash_value(string);
public:

    HashTable(int m){
        hashtable.resize(m);
        this->m = m;
    }

    // add number
    void add_n(string);

    // delete number
    void delete_n(string);

    // find number
    string find_n(string);

    //check list
    string check_list(int);
};

/** Rabin-Karp's algorithm for string matching
It based on instead of compare substrings compare hashes of substring
the main advantage of that the hash values are overlaps so computing the hashes isn't time consuming
O(|T|+|P|)
* naive algorithm : O(|P||T|)
H[i] = x*H[i+1] + T[i] - T[i+|P|] * x^(|P|)
*/
vector<int> find_str(const string&, const string&);
// split input to query into command and number and name
void execute_query(Query, HashTable&);

//phone book interface
void test();
#endif // HASHING_H_INCLUDED
