#include "hashing.h"

/**Phone book problem*/
PhoneBook phonebook;
// add number
void PhoneBook::add_number(string name, int num){
    phone_book[num] = name;
}

// find Number
string PhoneBook::find_number(int num){
    if(phone_book.find(num) != phone_book.end()) return phone_book[num];
    return "not found";
}

// delete Number
void PhoneBook::delete_number(int num){
    if(phone_book.find(num) != phone_book.end())
        phone_book[num] = "not found";
}


/**Hash Table using Chaining schema
*/

// hash function of string
int HashTable::hash_value(string name){
    unsigned long long hash_value = 0;

    for(int i = static_cast<int>(name.size()) - 1; i >= 0; i--)
        hash_value = (hash_value * X + name[i]) % P;

    return hash_value % m;
}

// check list
string HashTable::check_list(int index){
    string result = "";
    list<string>& chain = hashtable[index];
    list<string>::iterator it = chain.begin();

    // if chain list empty
    if(chain.empty()) return "";

    while(it != chain.end()){
        result += *it + ' ';
        it++;
    }
    return result.substr(0, result.length()-1);
}


//find name in hash table
string HashTable::find_n(string name){
    list<string>& chain = hashtable[hash_value(name)];
    if(find(chain.begin(), chain.end(), name) != chain.end())
        return "yes";
    return "no";

}


//delete number
void HashTable::delete_n(string name){
    hashtable[hash_value(name)].remove(name);
}


// add name the hash table
void HashTable::add_n(string name){
    int indx = hash_value(name);
    list<string>& elements = hashtable[indx];

    if(find(elements.begin(), elements.end(), name) == elements.end())
            elements.push_front(name);
}


string result;
//execute query
void execute_query(Query query, HashTable& ht){
    if(query.type == "add")
        ht.add_n(query.name);

    else if (query.type == "del")
        ht.delete_n(query.name);

    else if (query.type == "find")
        result += ht.find_n(query.name) + '\n';

    else if(query.type == "check")
        result += ht.check_list(query.number) + '\n';
}



//phone book interface
void test(){
     int m, n;
    cin >> m >> n;
    HashTable hash_table(m);
    Query query;

    for (int i = 0; i < n; ++i) {
        // read query
        cin >> query.type;
        if (query.type == "check")
            cin >> query.number;
        else
            cin >> query.name;
        //execute query
        execute_query(query, hash_table);
    }
    cout << result<< endl;
}

/***************************************/
/**Rabin-Karp's algorithm*/

// hash function of string
static ull PolyHash(const string& s){
    ull hv = 0;
    for (int i = int (s.size()) - 1; i >= 0; --i)
        hv = ((hv * X + s[i]) % P + P) % P;
    return hv;
}


static vector<ull> PreComputeHashes(const string& t, int pl){
    int tl = t.size();
    vector<ull> hashes(tl - pl + 1);
    hashes[hashes.size()-1] = PolyHash(t.substr(tl-pl));
    ull y = 1;

    for (int i=0; i < pl; i++)
        y = (y*X)%P;

    for(int i = hashes.size()-2; i >= 0; i--)
        hashes[i] = ((X*hashes[i+1] + t[i] - (y*t[i+pl]%P)) + P) %P;
    return hashes;
}


// compare 2 strings
static bool areEqual(const string& t, const string& p, int f){
    for(int i=0; i<p.size(); i++)
        if(p[i] != t[f+i])
            return false;
    return true;
}


vector<int> find_str(const string& t, const string& p){
    vector<int> ans;
    ull phash = PolyHash(p);
    cout << "mhash : " << phash << endl;
    vector<ull> hashes = PreComputeHashes(t, p.size());

    cout << "myprehashes : " << endl;
    for(auto& h : hashes) cout << h << " "; cout << endl;

    for(int i=0; i < hashes.size(); i++)
        if(hashes[i] == phash && areEqual(t, p, i))
            ans.push_back(i);
    return ans;
}
