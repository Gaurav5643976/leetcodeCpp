class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        if(n<m){
            return "";
        }
        int hashS[256]={0},hashT[256]={0};
        for(auto i:t){
            hashT[i]++;
        }
        int start = 0, start_index = -1, min_len = INT_MAX;
        int count = 0;
        for (int j = 0; j < n; j++) {
            hashS[s[j]]++;
            if (hashS[s[j]] <= hashT[s[j]]){
                count++;
            }
            if (count == m) {
                while (hashS[s[start]] > hashT[s[start]] or hashT[s[start]] == 0) {
                    if (hashS[s[start]]> hashT[s[start]]){
                        hashS[s[start]]--;
                    }
                    start++;
                }
                int len_window = j - start + 1;
                if (min_len > len_window) {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }
        if (start_index == -1) {
            return "";
        }
        return s.substr(start_index, min_len);
    }
};