#include "BasicDataStructures.h"

/// balanced brackets problem
bool isOpenBracket(char c){
    if(openBrackets.find(c) == string::npos)
        return false;
    return true;
}


bool isCloseBracket(char c){
    if(closeBrackets.find(c) == string::npos)
        return false;
    return true;
}


bool popMachedOne(stack<Bracket>& brackets, char closeBracket){
    static map<char, char> bracketsPairs = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    if(brackets.empty()) return false;

    char openBracket = brackets.top().bracket;
    brackets.pop();

    if(bracketsPairs[openBracket] == closeBracket) return true;
    return false;
}


// return the first unmatched bracket if brackets match return -1
int matchBrackets(const string& expr){
    stack<Bracket> brackets;

    // push when face open bracket and pop when face close bracket
    for(size_t i = 0; i < expr.size(); i++){
        if(isOpenBracket(expr[i])){
            brackets.push(Bracket(i+1, expr[i]));

        }else if(isCloseBracket(expr[i])){
                bool ok = popMachedOne(brackets, expr[i]);

                // if not OK return the index of mismatch
                if(!ok) return i+1;
        }
    }

    // check there is no open brackets if there is return the first one
    int indexFirstBadBracket = -1;

    while(!brackets.empty()){
        Bracket b = brackets.top();
        indexFirstBadBracket = b.index;
        brackets.pop();
    }

    return indexFirstBadBracket;
}


/**Tree Height
*/
INt_MATRIX readTree(int& root){
    int n, parent;
    cin >> n;
    INt_MATRIX tree(n, vector<int>());

    for(int node=0; node<n; node++){
        cin >> parent;
        if(parent == -1) {root = node; continue;}

        tree[parent].push_back(node);
    }

    return tree;
}


int treeHeight(const INt_MATRIX& tree, int node){
    int myMaxHeight = 1;
    for(size_t i = 0; i < tree[node].size(); i++){
        myMaxHeight = max(myMaxHeight, (1 + treeHeight(tree, tree[node][i])));
    }
    return myMaxHeight;
}


int treeHeight(){
    int root;
    INt_MATRIX tree = readTree(root);
    return treeHeight(tree, root);
}


/**Network packet processing simulation
*/
vector<Packet> readPackets(int n){
    vector<Packet> packets;
    int a, p;
    for(int i=0; i < n; i++){
       cin >> a >> p;
       packets.push_back({a, p});
    }

    return packets;
}


void popDonePackets(queue<Packet>& packets, int arrTime){
    while(!packets.empty()){
        Packet pac = packets.front();
        int finishTime = pac.startProcessing_time + pac.processing_time;

        // if the packet processed before the arrTime arrives pop it
        if(finishTime < arrTime)
            packets.pop();
        else break;
    }
}

void processPackets(vector<Packet>& packets, int S){
    int cpuFinishTime = 0;
    queue<Packet> buffer;
    int freeSpace = S - buffer.size();  // free space in the buffer

    // iterate through all packets
    for(size_t i=0; i < packets.size(); i++){
        // if the CPU is free before the current packet arrive then process it immediately
        if(packets[i].arrival_time >= cpuFinishTime){
            packets[i].startProcessing_time = packets[i].arrival_time;
            cpuFinishTime =  packets[i].arrival_time + packets[i].processing_time;
            buffer.push(packets[i]);

        }else{
            // CPU is busy when the packet arrive store it in the buffer
            // first pop out from the buffer all the packets that processed before the
            //current packet arrive.
            popDonePackets(buffer, packets[i].arrival_time);

            if((freeSpace = S - buffer.size()) > 0){
                // push the packet to processed later
                packets[i].startProcessing_time = cpuFinishTime;
                cpuFinishTime = cpuFinishTime + packets[i].startProcessing_time;
                buffer.push(packets[i]);
            }else{
                // drop out the packet
                packets[i].startProcessing_time = -1;
            }

        }
    }
}


void printPackets(vector<Packet>& packets){
    for(const auto& packet : packets)
        cout << packet.startProcessing_time << endl;
}


void packetProcessingSimulation(){
    int bufferSize, packetsNum;
    cin >> bufferSize >> packetsNum;

    /// read packets
    vector<Packet> packets = readPackets(packetsNum);

    /// process packets
    processPackets(packets, bufferSize);

    /// print results
    printPackets(packets);

}
