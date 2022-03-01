// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int count(int n){
        int c=0;
        while(n){
            c++;
            n/=10;
        }
        return c;
    }
    long long countPairs(int N, int X, vector<int> numbers){
        // code here
        long long ans=0;
        sort(numbers.begin(),numbers.end());
        int m=count(X);
        for(auto i:numbers){
            int n=count(i);
            //cout<<n<<" ";
            if(n<=m){
                int p=pow(10,n);
                //cout<<i<<"-->"<<endl;
                if(i==X%p){
                    int toFind=X/p;
                    if(count(toFind)==m-n){
                        //cout<<i<<" "<<"1"<<endl;
                        vector<int>::iterator l, h;
                        l=lower_bound(numbers.begin(),numbers.end(),toFind);
                        h=lower_bound(numbers.begin(),numbers.end(),toFind+1);
                        ans+=h-l;
                        if(i==toFind){
                            ans--;
                        }
                    }
                    //cout<<h-numbers.begin()<<" "<<l-numbers.begin()<<" ";
                }
                p=pow(10,m-n);
                if(i==X/p){
                    int toFind=X%p;
                    if(count(toFind)==m-n){
                        //cout<<i<<" "<<"2"<<endl;
                        vector<int>::iterator l, h;
                        l=lower_bound(numbers.begin(),numbers.end(),toFind);
                        h=lower_bound(numbers.begin(),numbers.end(),toFind+1);
                        ans+=h-l;
                        if(i==toFind){
                            ans--;
                        }
                    }
                    //cout<<h-numbers.begin()<<" "<<l-numbers.begin()<<endl;
                }
            }
        }
        return ans/2;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends