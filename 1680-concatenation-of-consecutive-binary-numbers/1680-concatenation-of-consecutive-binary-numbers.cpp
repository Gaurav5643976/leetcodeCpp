class Solution {
public:
    int concatenatedBinary(int n) {
          long long int ans=0;
          long long int cnt=1;
          int md=1e9+7;
          for(int i=n;i>=1;i--){

              //convert to binary and concatinate
              int m=i;
              while(m>0){
                    ans=(ans + (m%2 * cnt)%md)%md;
                    m=m/2;
                    cnt=(cnt<<1)%md;
              }

          }
          return ans%md;  
    }
};