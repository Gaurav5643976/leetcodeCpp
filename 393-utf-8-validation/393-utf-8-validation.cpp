class Solution {
public:
    bool validUtf8(vector<int>& data) {
         int rem = 0;
        
        for(int i : data){
            
            if(rem == 0){
               
               if((i>>5) == 0b110) {
                   rem = 1;
               }
               else if((i>>4) == 0b1110) {
                   rem=2;
               }
               else if((i>>3) == 0b11110) {
                   rem=3;
               }
               else if((i>>7) != 0) {
                   return false;
               }
                
             } else {
                if((i>>6) != 0b10) {
                    return false;
                }
                rem--;
            }
        }
        return rem == 0;
    }
};