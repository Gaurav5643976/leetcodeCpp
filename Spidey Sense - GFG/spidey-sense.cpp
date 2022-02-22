// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    #define pi pair<int,int> 

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        // Your code goes here
        queue<pi> q;
        vector<vector<int>> ans(M , vector<int> (N,-1));
        for(int i=0; i< M; i++ ){
            for(int j=0; j < N; j++ ){
                
                if(matrix[i][j] == 'B' ){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
               
            }
        }
        
        int x[] = {0,0,1,-1};
        int y[] = {-1,1,0,0};
        int lvl = 0;
        while(q.size()){
            lvl++;
            int qs = q.size();
            while(qs -- ){
                
                auto it = q.front();
                q.pop();
                
                for(int i=0;i < 4; i++ ){
                    int r = it.first + y[i];
                    int c = it.second + x[i];
                    
                    if(r < 0 || r >=M || c <0 || c >= N || matrix[r][c] != 'O' || ans[r][c] != -1 ){
                        continue;
                    }
                    
                    ans[r][c] = lvl;
                    
                    q.push({r,c});
                }
            }
        }
        
        return ans;
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends