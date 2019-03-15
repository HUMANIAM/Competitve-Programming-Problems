#include "poly_multi_problem.h"
#include <iostream>
#include <stdlib.h>

/// naive polynomials multiplication
vector<int> naive_poly_multiplication(const vector<int>& A, const vector<int>& B){
    int n = A.size() - 1;  // the max degree
    int m = B.size() - 1;   // the max degree
    int nc = n + m;         // the max result degree

    vector<int> C(nc+1, 0);

    for(int j=0; j<=n; j++)
        for(int i=0; i<=m; i++)
            C[i+j] += A[i]*B[j];

    return C;
}

/// polynomial multiplication using Divide and conquer approach
static void Add2Polynomials(vector<int>& A, vector<int>& B){
    //make them have the same size
    if(A.size() > B.size())
        for(int i=B.size(); i<A.size(); i++) B.push_back(0);
    else if(B.size() > A.size())
        for(int i=A.size(); i<B.size(); i++) A.push_back(0);

    for(size_t i=0; i<=A.size(); i++)
        A[i] += B[i];
}

static void append2Polynomials(vector<int>& A, vector<int>& B){
    for(const auto n : B) A.push_back(n);
}

static vector<int> scale_polynomial(const vector<int>& A, int scale, int from, int to){
    vector<int> C(to - from + 1);
    for(int i=from; i<= to; i++) C[i-from] = A[i] * scale;
    return C;
}

static void print(const vector<int>& v, int f, int t){
    for(int i=f; i<=t; i++) cout<<v[i]<<"  ";
    cout<<endl;
}

vector<int> recursive_poly_multiplication(const vector<int>& A, int Afrom, int Ato,
                                          const vector<int>& B, int Bfrom, int Bto){
    //base case
    int Asize = Ato - Afrom + 1;
    int Bsize = Bto - Bfrom + 1;
    if(Asize == 1){
        return scale_polynomial(B, A[Afrom], Bfrom, Bto);
    }
    else if (Bsize == 1)
        return scale_polynomial(A, B[Bfrom], Afrom, Ato);

    //recursive multiplication
    int A0_to = Afrom + Asize/2 - 1;
    int A1_from = Afrom + Asize/2;

    int B0_to = Bfrom + Bsize/2 - 1;
    int B1_from = Bfrom + Bsize/2;

    cout<<"A0 "; print(A, Afrom, A0_to);
    cout<<"A1 "; print(A, A1_from, Ato);
    cout<<"B0 "; print(B, Bfrom, B0_to);
    cout<<"B1 "; print(B, B1_from, Bto);
//    return vector<int>();


    //A0B0
    vector<int> U = recursive_poly_multiplication(A, Afrom, A0_to, B, Bfrom, B0_to);
    //A0B1
    vector<int> V = recursive_poly_multiplication(A, Afrom, A0_to, B, B1_from, Bto);
    //A1B0
    vector<int> W = recursive_poly_multiplication(A, A1_from, Ato, B, Bfrom, B0_to);
    //A1B1
    vector<int> Z = recursive_poly_multiplication(A, A1_from, Ato, B, B1_from, Bto);

    if(U.size() == 3) int x=1;
        //exit(0);
    else {
        cout<<"U "; print(U, 0, U.size()-1);
        cout<<"V "; print(V, 0, V.size()-1);
        cout<<"W "; print(W, 0, W.size()-1);
        cout<<"Z "; print(Z, 0, Z.size()-1);
    }
    //Add V and W
    Add2Polynomials(V, W);

    //return U + [V+W]X^(n/2) + Z^(2floor(n/2))
    append2Polynomials(U, V);
    append2Polynomials(U, Z);
    cout<<"**U "; print(U, 0, U.size()-1);
    return U;

}

///  using 4 multiplications operations
vector<int> polyn_mulitplication_DivideConquer_4Muli(const vector<int>& A, const vector<int>& B){
    return recursive_poly_multiplication(A, 0, A.size()-1, B, 0, B.size()-1);
}

