#include "Sorting.h"

/// kefa company
bool compare(const Friend& fr1, const Friend& fr2){
    return fr1.m < fr2.m;
}
ull findm(const Friend* friends, int n, int d){
    sort(friends, friends+n, compare);

    ull cmm = friends[0].f, mm = friends[0].f;
    int i = 1;
    for(int j=0, i=1; i<n && j<n; j++){
        if(j != 0)  cmm -= friends[j-1].f;
        while(i<n && friends[i].m - friends[j].m < d) cmm += friends[i++].f;
        mm = max(cmm, mm);
    }
    return mm;
}
