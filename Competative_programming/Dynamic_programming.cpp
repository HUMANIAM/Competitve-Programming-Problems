#include "Dynamic_programming.h"
#include <algorithm>
#include <iostream>
using namespace std;

/**Ugly Number Founder */
int maxDivision(int a, int b){
    while(a%b == 0)
        a/=b;
    return a;

}

bool isUgly(int n){
    int no = maxDivision(n, 2);
    no = maxDivision(no, 3);
    no = maxDivision(no, 5);

    return (no == 1)? true : false;
}

int findUglyNum_Naive(int n){
    int m = 1, coun = 1;

    while(n>coun){
        m++;
        if(isUgly(m)) coun++;
    }
    return m;
}

int minVal(int x, int y, int z){
    return min(min(x, y), z);
}

int findUglyNum_DB(int n){
    int uglies[n], i2=0, i3=0, i5=0;
    uglies[0] = 1;

    //find the remaining nth -1 uglies
    for(int m=1; m<n; m++){
        int minv = minVal(2*uglies[i2], 3*uglies[i3], 5*uglies[i5]);

        if(minv == 2*uglies[i2])  i2++;
        if(minv == 3*uglies[i3])  i3++;
        if(minv == 5*uglies[i5])  i5++;

        uglies[m] = minv;

    }
    return uglies[n-1];
}

/**coin exchange */
//first solution:
int coinExchange( int S[], int m, int n )
{
    //if n = 0 don't include any coins
    if (n == 0)
        return 1;

    //n<0 no solution
    if (n < 0)
        return 0;

    //set is empty you can change coins with n>0
    if (m <=0 && n >= 1)
        return 0;

    //C({a0, a1, ...., an}, N) = c({a0, a1, ......., an}, N-an)+c({a0, a1, ......., an-1}, N);
    return coinExchange( S, m - 1, n ) + coinExchange( S, m, n-S[m-1] );
}

//second solution
int coinExchangeDp( int S[], int m, int n )
{
    int i, j, x, y;

    // We need n+1 rows as the table is constructed
    // in bottom up manner using the base case 0
    // value case (n = 0)
    int table[n+1][m];

    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;

    // Fill rest of the table entries in bottom
    // up manner
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}

/** the minimum rest days*/
int FindMininum_restDays(int* arr, int n){
    int dp[n+1][3];
    //initialize the array
    for(int i=0; i<=n; i++)
        for(int j=0; j<3; j++)
            dp[i][j] = INT_MAX;
    dp[0][2] = 0;

    //apply dynamic programming for this problem we compute the first day and then next one
    for(int i=1; i<=n; i++){
        dp[i][2] = 1 + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
        if(arr[i] == 1 || arr[i] == 3)
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]);

        if(arr[i] == 2 || arr[i] == 3)
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
    }
    return min(min(dp[n][0], dp[n][1]), dp[n][2]);
}

/** K tree */
const int D = 1e9 + 7;
const int N = 111;
int arr[N][N];

int findPaths(int n, int k, int d){
    //memset(arr, -1, sizeof(arr));
    if(n==0 && d==0) return 1;
    if(d > n || n<0) return 0;

    if(arr[n][d] == -1){
        arr[n][d] = 0;
        for(int i=1; i<=k && i<=n; i++)
            arr[n][d] = (arr[n][d] + findPaths(n-i, k, Map(i, d)))%D;
    }
    return arr[n][d];
}

// another idea
void findPaths(){
    int f[111][3];
    int n, k, d;
	f[0][0] = 1;
	cin >> n >> k >> d;
	for (int i = 0; i < n; i++)
	for (int flag = 0; flag<=1; flag++)
	if (f[i][flag]>0){
		for (int next = 1; next <= k; next++){
			int sum = i + next;
			int nextflag = flag;
			if (next >= d) nextflag = 1;
			if (sum > n) continue;
			f[sum][nextflag] += f[i][flag];
			f[sum][nextflag] %= 1000000007;
		}
	}
	cout << f[n][1] << endl;
}

/// flowers problem
const int MAX=1e5+5;
const int D = 1e9+7;
int dp[MAX];
int total[MAX];

inline void Max_good_dinners(int k){
    dp[0] = 1;
    fora(i, 1, MAX){
        dp[i] = (i < k)? 1 : (dp[i-1] + dp[i-k])%D;
        total[i] = (total[i-1] + dp[i])%D;
    }
}
inline int get_max_good_dinners(int i){
    return total[i];
}
