class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
             return "1";
        
         string cnt = "";
         string prev = countAndSay(n-1);
         int i=0;
        
         while(i<prev.length()){
             char c = prev[i];
             int ct = 0;
             while(i<prev.length() && c==prev[i]){
                 i++;
                 ct++;
             }
             
             cnt+= to_string(ct) + c;
         }
        
        return cnt;
    }
};