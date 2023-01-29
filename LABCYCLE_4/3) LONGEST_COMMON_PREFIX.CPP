// PROBLEM LINK --- https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h> 
using namespace std ;

int min(int a,int b){
    if(a<b) return b ; else return a ;
}

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0)
    return string();
    if(strs.size()==1)
        return strs[0];
    int k = strs[0].size();
    int j = 0;
    int flag = 0;
    while(j<k){
        for(int i=1;i<strs.size();i++){
            if(strs[i].size()<j+1||strs[i][j]!=strs[i-1][j]){
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
        j++;
    }
    return strs[0].substr(0,j);
    }

int main(){
    int testCases ; cin >> testCases;
    while(testCases--){
        int n ; cin >> n ;
        vector<string> strs(n) ;
        for(int i=0 ; i<n ; i++) cin >> strs[i] ;
        cout << longestCommonPrefix(strs) << endl ;
    }
}
