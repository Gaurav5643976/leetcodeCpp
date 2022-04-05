class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int freq[26]={0};
        int left=0,right=0;
        int longestSubs=0;
        int flag=left;
        while(right<n and left<=right){
            if(flag==left){
                freq[s[right]-'A']++;
            }
            flag=left;
            int maxFreq=*max_element(freq,freq+26);
            int windowLen=right-left+1;
            int charNeeded=windowLen-maxFreq;
            cout<<maxFreq<<" "<<windowLen<<" "<<charNeeded<<endl;
            if(charNeeded<=k){
                longestSubs=max(longestSubs,windowLen);
                right++;
            }
            else{
                freq[s[left]-'A']--;
                left++;
            }
        }
        return longestSubs;
    }
};