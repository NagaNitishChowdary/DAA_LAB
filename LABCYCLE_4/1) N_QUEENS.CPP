// PROBLEM LINK --- https://leetcode.com/problems/n-queens/

#include<bits/stdc++.h>
 using namespace std ;
 
 void solve(int col , int n , vector<vector<string>> &ans , vector<string> &board , vector<int> &leftRow , vector<int> &lowerDiagonal , vector<int> &upperDiagonal){
    if(col == n){
        ans.emplace_back(board) ; return ;
    }
    for(int row= 0 ; row<n ; row++){
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
            board[row][col] = 'Q' ;
            leftRow[row] = 1 ;
            lowerDiagonal[row+col] = 1 ;
            upperDiagonal[n-1+col-row] = 1 ;
            solve(col+1,n,ans,board,leftRow,lowerDiagonal,upperDiagonal) ;
            board[row][col] = '.' ;
            leftRow[row] = 0 ;
            lowerDiagonal[row+col] = 0 ;
            upperDiagonal[n-1+col-row] = 0 ;
        }
    }
}
    
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans ;
    vector<string> board(n) ;
    string s(n,'.') ;
    for(int i=0 ; i<n ; i++) board[i] = s ;
    vector<int> leftRow(n,0) , lowerDiagonal(2*n-1) , upperDiagonal(2*n-1) ;
    solve(0,n,ans,board,leftRow,lowerDiagonal,upperDiagonal) ;
    return ans ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<vector<string>> knnc = solveNQueens(n) ;
        for(auto vctr:knnc){
            for(auto it:vctr) cout << it << endl ;
            cout << endl ; cout << endl ;
        }
    }
    return 0 ;
}
