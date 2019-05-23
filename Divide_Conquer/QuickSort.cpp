#include "QuickSort.h"

static void partition3(vector<int> &a, int l, int r, int& m1, int& m2) {
    //select random pivot
    int k = l + rand() % (r - l + 1);
    int pivot = a[k];

    //swap it to most right position in the array
    swap(a[r], a[k]);

    int equalptr = r-1;
    int firstGreat = l, iter = l;

    while( iter <= equalptr ) {
        if (a[iter] < pivot)
            swap(a[iter++], a[firstGreat++]);
        else if(a[iter] == pivot)
            swap(a[iter], a[equalptr--]);
        else
            iter++;
   }

  m1=firstGreat;
  int j = firstGreat;

  //shift equal part into the center
  for(int k=r; k>equalptr; k--)
    swap(a[j++], a[k]);
  m2 = j - 1;

}

// randomize quick sortvoid randomized_quick_sort(vector<int> &a, int l, int r) {
void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r)
    return;

  int m1,m2;
  partition3(a, l, r, m1, m2);
  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}
