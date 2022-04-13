class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,0));
        //memset(v,0,sizeof(v));
        char st='U';
        int x=0,y=0;
        for(int i=1;i<=n*n;i++){
            v[x][y]=i;
            //cout<<x<<" "<<y<<" "<<st<<endl;
            if(st=='U'){
                if(x-1>=0 and v[x-1][y]==0){
                    x--;
                }
                else{
                    y++;
                    st='R';
                }
            }
            else if(st=='R'){
                if(y+1<n and v[x][y+1]==0){
                    y++;
                }
                else{
                    x++;
                    st='D';
                }
            }
            else if(st=='D'){
                if(x+1<n and v[x+1][y]==0){
                    x++;
                }
                else{
                    y--;
                    st='L';
                }
            }
            else if(st=='L'){
                if(y-1>=0 and v[x][y-1]==0){
                    y--;
                }
                else{
                    x--;
                    st='U';
                }
            }
        }
        return v;
    }
};