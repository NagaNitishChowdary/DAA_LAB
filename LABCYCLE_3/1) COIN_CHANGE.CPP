// PROBLEM LINK ---  https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int ind,int amount,vector<int> &coins){
    if(ind == 0){
        if(amount%coins[ind] == 0) return amount/coins[ind] ;
        else return 1e9 ;
    }
    int notPick = 0 + recursion(ind-1,amount,coins) ;
    int pick = INT_MAX ;
    if(coins[ind] <= amount) pick = 1 + recursion(ind,amount-coins[ind],coins);
    return min(pick,notPick) ;
}

int memorization(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp){
    if(ind == 0){
        if(amount%coins[ind] == 0) return amount/coins[ind] ;
        else return 1e9 ;
    }
    if(dp[ind][amount] != -1) return dp[ind][amount] ;
    int notPick = 0 + memorization(ind-1,amount,coins,dp);
    int pick = INT_MAX ;
    if(coins[ind] <= amount) pick = 1 + memorization(ind,amount-coins[ind],coins,dp);
    return dp[ind][amount] = min(notPick,pick) ;
}

int coinChange(vector<int>& coins, int amount)
{
    // Write your code here.
    // RECURSION
    // int n = coins.size() ;
    // int ans = recursion(n-1,amount,coins);
    // if(ans >= 1e9) return -1;
    // return ans ;
    
    // MEMORIZATION
    int n = coins.size() ;
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    int ans = memorization(n-1,amount,coins,dp) ;
    if(ans >= 1e9) return -1 ;
    else return ans ;
}

int main(){
    int testCases ; cin >> testCases;
    while(testCases--){
        int n,amount ;
        cin >> n ;
        vector<int> coins(n) ;
        for(int i=0 ; i<n ; i++) cin >> coins[i] ;
        cin >> amount ;
        cout << coinChange(coins,amount) << "\n" ;
    }
}
