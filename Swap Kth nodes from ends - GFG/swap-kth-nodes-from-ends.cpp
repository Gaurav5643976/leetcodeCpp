// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int k)
{
    // Your Code here
    Node* temp=head;
    int nodeCount=0;
    while(temp){
        temp=temp->next;
        nodeCount++;
    }
    if(k>nodeCount){
        return head;
    }
    if(k==1 or k==nodeCount){
        //cout<<0;
        Node *sP=head,*fP=head,*fPprev=NULL;
        nodeCount--;
        while(nodeCount--){
            fPprev=fP;
            fP=fP->next;
        }
        fP->next=sP->next;
        fPprev->next=sP;
        sP->next=NULL;
        head=fP;
    }
    else{
        Node *sP=head,*fP=head,*fPprev=NULL,*sPprev=NULL;
        int c=k-1;
        while(c--){
            sPprev=sP;
            sP=sP->next;
        }
        c=nodeCount-k;
        while(c--){
            fPprev=fP;
            fP=fP->next;
        }
        sPprev->next=fP;
        fPprev->next=sP;
        Node* t=sP->next;
        sP->next=fP->next;
        fP->next=t;
    }
    return head;
}
