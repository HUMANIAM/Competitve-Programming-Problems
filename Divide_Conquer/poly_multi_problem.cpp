#include "poly_multi_problem.h"
/// naive polynomials multiplication
vector<int> naive_poly_multiplication(const vector<int>& A, const vector<int>& B){
    int n = A.size() - 1;  // the max degree
    int m = B.size() - 1;   // the max degree
    int nc = n + m;         // the max result degree

    vector<int> AA = A;
    vector<int> BB = B;
    vector<int> C(nc+1, 0);

    for(int i=n+1; i<=nc; i++) AA.push_back(0);
    for(int i=m+1; i<=nc; i++) BB.push_back(0);

    for(int k=0; k<=n+m; k++){
        for(int i=0; i<=k; i++)
            C[k] += AA[i]*BB[k-i];
    }
    return C;
}
