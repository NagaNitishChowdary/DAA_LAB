// RABIN KARP STRING MATCHING ALGORITHM 

#include<bits/stdc++.h>
#define d 256 // d is the number of characters in the input alphabet
using namespace std ;

void solve(string text,string pattern,int q){
    int m = pattern.size() , n = text.size() ;
    int i , j , p = 0 , t = 0 ;

    int h = 1 ;
    for(i=0 ; i<m-1 ; i++) h = (h*d)%q ;

    for(int i=0 ; i<m ; i++){
        p = (d*p + pattern[i])%q ;
        t = (d*t + text[i])%q ;
    }

    for(int i=0 ; i<n-m ; i++){
        // SLIDE THE WINDOW OVER TEXT ONE BY ONE
        if(p == t){
            // IF HASH VALUES ARE EQUAL THEN CHECK FOR CHARACTERS ONE BY ONE
            for(j=0 ; j<m ; j++){
                if(text[i+j] != pattern[j]) break ;
            }

            if(j == m) cout << "PATTERN FOUND AT INDEX " << i << endl ;
        }

        if(i < n-m){
            t = (d*(t-text[i]*h) + text[i+m])%q ;
            if(t < 0) t = (t+q) ;
        }
    }
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        string text , pattern ;
        cin >> text >> pattern ;
        int q = INT_MAX ;
        solve(text,pattern,q) ;
    }
    return 0 ;
}
