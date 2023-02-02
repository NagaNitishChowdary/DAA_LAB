#include<bits/stdc++.h>
using namespace std;

// USING BELLMAN FORD ALGORITHM
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> dist(n+1,1e9) ;
    dist[k] = 0 ;
    for(int i=0 ; i<n-1 ; i++){
        for(auto it:times){
            int u = it[0] , v = it[1] , wt = it[2] ;
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt ;
            }
        }
    }
    int maxi = 0 ;
    for(int i=1 ; i<=n ; i++){
        maxi = max(maxi , dist[i]) ;
    }
    if(maxi == 1e9) return -1 ;
    return maxi ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ; 
    while(testCases--){
        int m ; cin >> m ;
        vector<vector<int>> times ;
        for(int i=0 ; i<m ; i++){
            vector<int> knnc(3) ;
            cin >> knnc[0] ; cin >> knnc[1] ; cin >> knnc[2] ;
            times.push_back(knnc) ;
        }
        int n , k ; cin >> n >> k ;
        cout << networkDelayTime(times,n,k) << endl ;
    }
    return 0;  
}
