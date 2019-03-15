#include "binarySearch.h"

/// find an element in a list
static int binary_ser(const vector<int> arr, int left, int right, int element){
    //base case
    if(left > right)
        return -1;
    int mid = left + (right - left)/2;

    if(arr[mid] == element)
        return mid;
    else{
        if(arr[mid] > element)
            return binary_ser(arr, left, mid-1, element);
        else
            return binary_ser(arr, mid+1, right, element);
    }
}

int Element_in_List(const vector<int>& elements, int element){
    return binary_ser(elements, 0, elements.size(), element);
}
