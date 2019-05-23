#include "MergeSort.h"

static void set_sub_lists(const vector<int>& elements, vector<int>& leftLst, vector<int>& rightLst,
                          int left, int center, int right){
    size_t i = left;
    // set left sublist
    while(i <= center) leftLst.push_back(elements[i++]);

    //push max size of type of int at the end
    leftLst.push_back(1 << 30);

    //set the right sublist
    while(i <= right) rightLst.push_back(elements[i++]);

    //push max size of type int at the end
    rightLst.push_back(1 << 30);
}

void put_in_order(vector<int>& elements, vector<int>& leftLst, vector<int>& rightLst,
                          int left, int center, int right){

    int leftSz = (center - left + 1);
    int rightSz = (right - center);

    size_t k = left, i = 0, j = 0;

    while(i < leftSz || j < rightSz){
        if(leftLst[i] < rightLst[j])
            elements[k++] = leftLst[i++];
        else
            elements[k++] = rightLst[j++];
    }
}

static void combine_sorted_lists(vector<int>& elements, int left, int center, int right){
    // temporary holders of left sublist and right list
    vector<int> leftList, rightList;

    //set those lists with the elements from the original list
    set_sub_lists(elements, leftList, rightList, left, center, right);

    //put them in order in the original list
    put_in_order(elements, leftList, rightList, left, center, right);
}

void merge_sort(vector<int>& elements, int left, int right){
    //base case
    if(left == right)
        return;

    //divide the current sublist into two smaller lists
    int center = (left + right)/2;
    merge_sort(elements, left, center);
    merge_sort(elements, center + 1, right);

    //combined them in a sorted order
    combine_sorted_lists(elements, left, center, right);
}
