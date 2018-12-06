#include "Gready_problems.h"
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
//using namespace std;
/** problems of greedy technique*/

int changewith(int m, int coin, int& num){
    num += m / coin;
    return m -= coin * (m/coin);
}

int minCoins(int m){
    int num = 0;
    m = changewith(changewith(changewith(m, 10, num), 5, num), 1, num);
    return num;
}

/**  Fractional knapsack problem*/

float fractionalKnapsack(int W, int* weights, int* values, int n){
    priority_queue<Item> pq_items;
    float maxProfit = 0;

    // push items into the priority queue
    for(int i=0; i<n; i++) pq_items.push(Item(weights[i], values[i]));

    while(W != 0 && !pq_items.empty()){
        const Item& top = pq_items.top();
        maxProfit += top.vPerw * min(top.w, W);
        W -= min(top.w, W);
        pq_items.pop();
    }

    return maxProfit;
}

/**   Maximizing Revenue in Online Ad Placement */

double maxRevenue(int* ads_profit, int* ads_clicks_perday, int n){
    sort(ads_profit, ads_profit + n);
    sort(ads_clicks_perday, ads_clicks_perday + n);

    double result = 0;
    for(int i=0; i<n; i++) result += ads_clicks_perday[i] * ads_profit[i];

    return result;
}

/** Collecting Signatures */

void minPoints_touchAllSegments(const int* pstart, int* pend, int n, vector<Point>& points){
    int m = 0;
    priority_queue<Point> pq_points;

    for(int i=0; i<n; i++) pq_points.push(Point(pstart[i], pend[i]));

    // read the minimum number of points touch every segment
    Point point = pq_points.top();  //start point
    pq_points.pop();
    points.push_back(point);

    while(!pq_points.empty()){
        //remove all segments that end of current segment touch
        while(!pq_points.empty())
            if(point.to >= pq_points.top().from)
                pq_points.pop();
            else break;

        if(!pq_points.empty()){
            //new start point
            point = pq_points.top();  //start point
            pq_points.pop();
            points.push_back(point);
        }
    }
}


/** Maximizing the Number of Prize Places in a Competition*/

void makeChildren_happy(int n, vector<int>& prizes){
    int nwrank = 1;
    while(n != 0){
    if( (n -= nwrank) <= nwrank )
    {
        nwrank += n;
        n=0;
    }
    prizes.push_back(nwrank++);
  }
}

/** Maximizing Your Salary */

bool isGreater(const string& s1, const string& s2){
    int i=0, j=0;
    bool s1_done = false, s2_done = false;

    while(!s1_done || !s2_done){
        if(i == s1.length()) s1_done = true;
        if(j == s2.length()) s2_done = true;

        i = i % s1.length();
        j = j % s2.length();

        if( s1[i] > s2[j] )
             return true;
        else if( s1[i] < s2[j] )
            return false;

        i++; j++;
    }
    return true;
}

string findMax_salary(const vector<string>& numbers, int n){
    priority_queue<Number> pq_numbers;
    for(int i=0; i<n; i++) pq_numbers.push(Number(numbers[i]));

    string res = "";
    while(!pq_numbers.empty()){
        res += pq_numbers.top().number;
        pq_numbers.pop();
    }
    return res;
}
