// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
     Node* reverseBetween(Node* head, int m, int n)
   {
       //code here
       if(head==NULL)
           return head;
       int temp = m;
       Node *prev1 = NULL;
       Node *temp1 = head;
       Node *temp2 = head;
       while(--m){
           prev1 = temp1;
           temp1 = temp1 -> next;
       }
       while(--n){
           temp2 = temp2 -> next;
       }
       Node *prev = temp1;
       Node *cur =  temp1->next;
       Node *nextnode;
       if(prev1)
           prev1 -> next = temp2;
       temp1 -> next = temp2 -> next;
     
       while(prev!=temp2){
           nextnode = cur -> next;
           cur -> next = prev;
           prev = cur;
           cur  = nextnode;
       }
       if(temp==1)
           return temp2;
       return head;
   }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends