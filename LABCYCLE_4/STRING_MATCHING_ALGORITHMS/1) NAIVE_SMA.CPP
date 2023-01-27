#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// STRING MATCHING ALGORITHMS 
// NAIVE STRING MATCHING ALGORITHM (BRUTEFORCE)

// TIME COMPLEXITY --- O(N^2)
// SPACE COMPLEXITY --- O(1)

void naive_string_matching_algorithm(){
    int n , m ;
    cin >> n >> m ;
    string str1 , str2 ;
    cin >> str1 >> str2 ;
    for(int i=0 ; i<n-m ; i++){
        int k = i , j ;
        if(str1[i] != str2[0]) continue ;
        for(j=0 ; j<m ; j++){
            if(str1[k++] != str2[j]) break ;
        }
        if(j == m){
            cout << "string matched at index " << i << endl ;
            return ;
        }
    }
    cout << "string not matched" << endl ;
}

int main() {
    int test ; cin >> test ;
    while(test--){
        naive_string_matching_algorithm() ;
    }
    return 0 ;
}
