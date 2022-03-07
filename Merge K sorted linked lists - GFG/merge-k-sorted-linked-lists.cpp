// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
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

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* mergeTwoLists(Node* list1, Node* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        Node* mergedList=NULL;
        if(list1->data<=list2->data){
            mergedList=list1;
            mergedList->next=mergeTwoLists(list1->next,list2);
        }
        else{
            mergedList=list2;
            mergedList->next=mergeTwoLists(list1,list2->next);
        }
        return mergedList;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
            if(K==1){
                return arr[0];
            }
            Node* mergedList=arr[0];
            for(int i=1;i<K;i++){
                mergedList=mergeTwoLists(mergedList,arr[i]);
            }
            return mergedList;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends