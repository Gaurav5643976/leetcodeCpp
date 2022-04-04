class Solution {
public:
    int minSteps(int n) {
        int ans=0;
        // 1->0
        // 2->CP
        // 3->CPP
        // 4-> 2*2 -> CPCP
        // 5->CPPPP
        // 6-> 2*3->CPCPP
        // 7-> CPPPPPP
        // 8-> 2*2*2-> CPCPCP
        // 9-> 3*3-> CPPCPP
        // 10-> 2*5 -> CPCPPPP
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                ans+=i;
                n/=i;
            }
        }
        // if prime
        if(n!=1){
            ans+=n;
        }
        return ans;
    }
};