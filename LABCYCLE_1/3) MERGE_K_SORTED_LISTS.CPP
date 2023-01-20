// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// PROBLEM LINK --- https://leetcode.com/problems/merge-k-sorted-lists/

#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}
  
Node* mergeTwoLists(Node* list1, Node* list2) {
    if(list1 == NULL) return list2 ;
    if(list2 == NULL) return list1 ;
    Node *ptr ;
    if(list1 -> data > list2 -> data){
        ptr = list2 ;
        list2 = list2 -> next ;
    }
    else{
        ptr = list1 ;
        list1 = list1 -> next ;
    }
    Node *curr = ptr ;
    while(list1 && list2){
        if(list1 -> data > list2 -> data){
            curr -> next = list2 ;
            list2 = list2 -> next ;
        }
        else{
            curr -> next = list1 ;
            list1 = list1 -> next ;
        }
        curr = curr -> next ;
    }
    // IF LIST 2 IS NULL
    if(list1){
        curr -> next = list1 ;
    }
    // IF LIST 1 IS NULL
    if(list2){
        curr -> next = list2 ;
    }
    return ptr ;
}
  
//Function to merge K sorted linked list.
Node * mergeKLists(Node *arr[], int K)
{
    Node *head = arr[0] ;
    for(int i=1 ; i<K ; i++) head = mergeTwoLists(head,arr[i]) ;
    return head ;
}

int main()
{
   int t ; cin >> t ;
   while(t--)
   {
	   int N ; cin >> N ;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n ; cin >> n ;
           int x ; cin >> x ;
           arr[j] = new Node(x);
           Node *curr = arr[j];
           n-- ;
           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Node *res = mergeKLists(arr,N);
		printList(res);
   }
	return 0;
}
