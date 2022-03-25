class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int n=digits.size();
        int carry=1;
        for(int i=0;i<n;i++){
            int val=carry+digits[i];
            digits[i]=val%10;
            carry=val/10;
        }
        if(carry){
            digits.push_back(carry);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};