#include "MajorElement.h"

static int count_occurrences(const vector<int>& elements, size_t from, size_t to, int element){
    int countOccurs = 0;
    for(int i = from; i <= to; i++)
        if(elements[i] == element)
            countOccurs++;
    return countOccurs;
}

static MajorElment compare_majorities(const vector<int>& elements, size_t left, size_t center, size_t right,
                                MajorElment majorleft, MajorElment majorright){
   // count occurrence of left major element in the right part
   majorleft.occurrence += count_occurrences(elements, center + 1, right, majorleft.element);

   //count occurrence of right major element in the left part
   majorright.occurrence += count_occurrences(elements, left, center, majorright.element);

    int halfSize = (right - left + 1)/2;
   //left major has overall majority
   if (majorleft.occurrence > halfSize)
        return majorleft;

   //right major has overall majority
   if (majorright.occurrence > halfSize)
    return majorright;

    //no majority
    return MajorElment();
}

void print_list(vector<int> vec, int f, int t){
    int i = f;
    while(i <= t) cout << vec[i++] << " ";
    cout<<endl;
}
//5 1 2 2 2 3
MajorElment find_major_element(const vector<int>& elements, size_t left, size_t right){
    //base case
    if(left > right)
        return MajorElment();
    else if (left == right)
        return MajorElment(elements[left], 1);

    // divide the sublist int sublists
    int center = (right + left)/2;

    //find major element in the left part
    MajorElment majorLeft = find_major_element(elements, left, center);

    //find the major element in the right part
    MajorElment majorRight = find_major_element(elements, center + 1, right);

    //if major element in the left part = major element the right part then there is no
    //major element in the current sublist
    if(majorLeft.element == majorRight.element)
        return MajorElment();

    //if m1 != m2 then there is must one of them has majority over all the current list
    MajorElment me =  compare_majorities(elements, left, center, right, majorLeft, majorRight);
    return me;
//    return compare_majorities(elements, left, center, right, majorLeft, majorRight);
}
