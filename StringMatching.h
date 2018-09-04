#ifndef STRINGMATCHING_H_INCLUDED
#define STRINGMATCHING_H_INCLUDED
#include <string>
using namespace std;
/*  String matching used to find the position of pattern in text and it is used in many apps so
    we need to optimize it
    Applications : * searching in text editor, browser, database
    -------------  * in general pattern search algorithms
*/

//              Naive search algorithm
//              **********************
/*
    method : for every char in pattern (m length) has corresponding char in text (n length)
    -------
    analysis: best case :: the first char not match >>>> O(n-m+1)
    ------- : worst case :: at every position in text pattern is found >>> O(m*(n-m+1))
                            or last char of pattern mismatch >>> O(m*(n-m+1))
*/

// this algorithm check if a text consist of a specific patterns or not
// patterns : R, RY, RYY . we can combine them into RYY
void stringMatch(string&);

#endif // STRINGMATCHING_H_INCLUDED
