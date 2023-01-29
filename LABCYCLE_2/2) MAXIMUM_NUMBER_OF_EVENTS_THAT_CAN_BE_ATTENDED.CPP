// PROBLEM LINK --- https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

#include<bits/stdc++.h>
using namespace std;

int maxEvents(vector<vector<int>>& events) {
    int size = events.size() , i = 0 , ans = 0 ;
    priority_queue<int,vector<int> ,greater<int>> pq ;
    sort(events.begin() , events.end()) ;
    for(int days=1 ; days<=100000 ; days++){
        while(pq.size() && pq.top() < days) pq.pop() ;
        while(i<size && events[i][0] == days) pq.push(events[i++][1]) ;
        if(pq.size()){
            pq.pop() ; ans++ ;
        }
    }
    return ans ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ; 
    while(testCases--){
        int n ; cin >> n ;
        vector<vector<int>> events ;
        for(int i=0 ; i<n ; i++){
            vector<int> knnc(2) ;
            cin >> knnc[0] ; cin >> knnc[1] ; 
            events.push_back(knnc) ;
        }
        cout << maxEvents(events) << endl ;
    }
    return 0;  
}
