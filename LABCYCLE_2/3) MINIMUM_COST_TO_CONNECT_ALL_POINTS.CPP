// PROBLEM LINK --- https://leetcode.com/problems/min-cost-to-connect-all-points/

#include<bits/stdc++.h>
using namespace std;

// INITIALLY WE ASSUME THAT ALL NODES ARE CONNECTED 
// AND WE APPLY MINIMUM SPANNING TREE --- KRUSHKAL'S ALGORITHM 

int parent[1001] ; 

int findPar(int i){
    if(parent[i] == -1) return i ;
    return parent[i] = findPar(parent[i]) ;
}

void Union(int a,int b){ parent[a] = b ; }

int minCostConnectPoints(vector<vector<int>>& points) {
    int size = points.size() ;
    for(int i=0 ; i<size ; i++) parent[i] = -1 ;
    vector<pair<int,pair<int,int>>> adj ;
    for(int i=0 ; i<size ; i++){
        for(int j=i+1 ; j<size ; j++){
            int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) ;
            adj.push_back({weight,{i,j}}) ;
        }
    }

    // SORTING ALL THE EDGES TO TAKE MINIMUM COST EDGES 
    sort(adj.begin() , adj.end()) ;

    int sum = 0 ;
    for(int i=0 ; i<adj.size() ; i++){
        int a = findPar(adj[i].second.first) ;
        int b = findPar(adj[i].second.second) ;
        if((a) != (b)){
            Union(a,b) ; sum += adj[i].first ;
        }
    }
    return sum ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ; 
    while(testCases--){
        int n ; cin >> n ;
        vector<vector<int>> points ;
        for(int i=0 ; i<n ; i++){
            vector<int> knnc(2) ;
            cin >> knnc[0] ; cin >> knnc[1] ;
            points.push_back(knnc) ;
        }
        cout << minCostConnectPoints(points) << endl ;
    }
    return 0;  
}
