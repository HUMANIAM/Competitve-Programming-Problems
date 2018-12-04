#include <iostream>
#include <string>
#include <algorithm>
#include "StringMatching.h"
using namespace std;

// implementation of naive pattern searching algorithm
void stringMatch(string& s){
    const string pat = "RYY";
    int n = s.length(), i=0;
    while(i<n)
        for(int j=0; j<3; j++)
            if(s[i]==pat[j]){
                i++;
                if(i==n) break;
            }else{
                if((s[i]!='Y' && s[i]!='R') || (j==0 && s[i]=='Y')){
                    cout<<"NO"<<endl;
                    return;
                }
            }
    cout<<"YES"<<endl;
}

//************************************************//
