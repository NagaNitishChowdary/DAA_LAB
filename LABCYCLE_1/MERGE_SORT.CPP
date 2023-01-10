#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int b[high+1] ;
    int i = low ;
    int j = mid+1 ;
    int k = low ;
    while(i <= mid && j <= high){
        if(arr[i] >= arr[j]) b[k++] = arr[j++] ;
        else b[k++] = arr[i++] ;
    }
    while(i <= mid) b[k++] = arr[i++] ;
    while(j <= high) b[k++] = arr[j++] ;
    for(int i=low ; i<=high ; i++) arr[i] = b[i] ;
}

void mergesort(int arr[],int low,int high){
    if(low>=high) return ;
    int mid = low + (high-low)/2 ;
    mergesort(arr,low,mid) ;
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main()
{
    int n ; cin >> n ;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i] ;
     mergesort(arr,0,n-1);
    for(int i=0;i<n;i++) cout << arr[i] << " " ;
    cout << endl;
}
