#include <bits/stdc++.h> 
using namespace std ;

int lengthOfLongestSubstring(string s) {
    int size = s.size() ;
    int l=0 , r=0 ;
    int maxi = 0 ;
    set<int> st ;
    while(r<size){
        if(st.count(s[r]) == 0){
            maxi = max(maxi , r-l+1) ;
            st.insert(s[r]) ;
            r++ ;
        }
        else{
            while(st.count(s[r])>0){
                st.erase(s[l]) ;
                l++ ;
            }
        }
    }
    return maxi ;
}

int main(){
    int t ; cin >> t ;
    while(t--){
        string s ; cin >> s ;
        cout << lengthOfLongestSubstring(s) << endl;
    }
    return 0; 
}
