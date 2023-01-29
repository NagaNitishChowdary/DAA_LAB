#include<bits/stdc++.h>
using namespace std;

// USING BELLMAN FORD ALGORITHM
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> dist(n+1,1e9) ;
    dist[k] = 0 ;
    for(int i=0 ; i<n-1 ; i++){
        for(auto it:times){
            int u = it[0] ;
            int v = it[1] ;
            int wt = it[2] ;
            // IF THE NODE IS REACHABLE 
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

// USING DIJKSTRA'S ALGORITHM 
int networkDelayTimeDijkstra(vector<vector<int>>& times, int n, int k) {
    vector<vector<int>> adj[n+1];
    int i=0;
    int edges = times.size() ;
    while (i<edges) {
        int u, v, w;
        u = times[i][0] ;
        v = times[i][1] ;
        w = times[i][2] ;
        vector<int> t1,t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        // t2.push_back(u);
        // t2.push_back(w);
        // adj[v].push_back(t2);
        i++ ;
    }
    int source = k ;
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
    vector<int> dist(n+1,1e9) ;
    dist[source] = 0 ;
    pq.push({0,source}) ;

    while(!pq.empty()){
        int dis = pq.top().first ;
        int node = pq.top().second ;
        pq.pop() ;

        for(auto it:adj[node]){
            int edgeWeight = it[1] ;
            int adjNode = it[0] ;
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight ;
                pq.push({dist[adjNode] , adjNode}) ;
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
