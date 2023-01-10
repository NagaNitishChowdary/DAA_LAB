#include <bits/stdc++.h> 
using namespace std ;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0)) ;
    for(int i=weight[0] ; i<=maxWeight ; i++) dp[0][i] = value[0] ;
    for(int ind=1 ; ind<n ; ind++){
        for(int w=0 ; w<=maxWeight ; w++){
            int notPick = 0 + dp[ind-1][w] ;
            int pick = INT_MIN ;
            if(weight[ind] <= w) pick = value[ind] + dp[ind-1][w - weight[ind]] ;
            dp[ind][w] = max(pick , notPick) ;
        }
    }
    return dp[n-1][maxWeight] ;
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
        int n; cin >> n;
        vector<int> weight(n),value(n);
        for(int i=0 ; i<n ; i++) cin >> weight[i] ;
        for(int i=0 ; i<n ; i++) cin >> value[i] ;
        int maxWeight; cin >> maxWeight ;
        cout <<  knapsack(weight,value,n,maxWeight) << endl ;
    }
}
