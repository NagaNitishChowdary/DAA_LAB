// PROBLEM LINK --- https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>
using namespace std;

// MOST OPTIMIZED APPROACH --- USING COMBINATIONS
int uniquePaths(int m,int n){
    int N = n+m-2 , r = m-1 ; // r can be n-1
    double res = 1 ;
    // WE ARE CALCULATION NCR
    for(int i=1; i<=r ; i++) res = res*(N-r+i)/i ;
    return (int)res ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ; 
    while(testCases--){
        int m , n ; cin >> m >> n ;
        cout << uniquePaths(m,n) << endl ;
    }
    return 0;  
}
