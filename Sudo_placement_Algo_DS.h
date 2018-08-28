#ifndef SUDO_PLACEMENT_ALGO_DS_H_INCLUDED
#define SUDO_PLACEMENT_ALGO_DS_H_INCLUDED
#include<string>
using namespace std;
typedef long long ll;

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


#endif // SUDO_PLACEMENT_ALGO_DS_H_INCLUDED
