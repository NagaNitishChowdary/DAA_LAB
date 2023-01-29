// PROBLEM LINK --- https://leetcode.com/problems/reverse-words-in-a-string/

#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    vector<string> vt1 ;
    int size = s.size() ;
    string knnc = "" ;
    for(int i=0 ; i<size ; i++){
        if(s[i]== ' ' && knnc != ""){ vt1.emplace_back(knnc) ;
                                     knnc = "" ; }
        else if(s[i]==' ') continue ;
        else knnc += s[i] ;
    }
    if(s[size-1] != ' ') vt1.emplace_back(knnc) ;
    string ans = "" ;
    reverse(vt1.begin() , vt1.end()) ;
    int size1 = vt1.size() ;
    for(int i=0 ; i<size1 ; i++){
        ans += vt1[i] ;   if(i!=size1-1) ans += " " ;
    }
    return ans ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ; 
    while(testCases--){
        // string s ; cin >> s ;
        string s = "the sky is blue" ;
        cout << reverseWords(s) << endl ;
    }
    return 0;  
}
