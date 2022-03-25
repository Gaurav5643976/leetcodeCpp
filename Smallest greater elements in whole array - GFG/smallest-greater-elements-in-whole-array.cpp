// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}
// } Driver Code Ends


int* greaterElement(int arr[], int n)
{
    // Complete the function
    int *ans=new int[n];
    set<int> st;
    int ma=INT_MIN;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
        ma=max(ma,arr[i]);
    }
    for(int i=0;i<n;i++){
        if(ma==arr[i]){
            ans[i]=-10000000;
        }
        else{
            auto itr=st.find(arr[i]);
            itr++;
            ans[i]=*itr;
        }
    }
    return ans;
}
