class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k!=1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans=s;
        int n=s.size();
        int m=n+1;
        while(m--){
            int indx=0;
            char maChar=s[0];
            for(int i=1;i<k;i++){
                if(maChar<s[i]){
                    indx=i;
                    maChar=s[i];
                }
            }
            string t=s.substr(0,indx)+s.substr(indx+1,n-indx-1)+maChar;
            //cout<<s.substr(0,indx)<<" "<<s.substr(indx+1,n-indx-1)<<" "<<maChar<<" "<<indx<<" ";
            //cout<<t<<endl;
            s=t;
            ans=min(s,ans);
        }
        return ans;
    }
};