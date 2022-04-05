class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int freq[26]={0};
        int left=0,right=0;
        int longestSubs=0;
        bool flag=true;
        while(right<n and left<=right){
            if(flag==true){
                freq[s[right]-'A']++;
            }
            int maxFreq=*max_element(freq,freq+26);
            int windowLen=right-left+1;
            int charNeeded=windowLen-maxFreq;
            cout<<maxFreq<<" "<<windowLen<<" "<<charNeeded<<endl;
            if(charNeeded<=k){
                longestSubs=max(longestSubs,windowLen);
                right++;
                flag=true;
            }
            else{
                freq[s[left]-'A']--;
                left++;
                flag=false;
            }
        }
        return longestSubs;
    }
};