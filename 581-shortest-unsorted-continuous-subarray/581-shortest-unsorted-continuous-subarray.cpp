class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
            int n = A.size(), beg = -1, end = -2, mi = A[n-1], ma = A[0];
            for (int i=1;i<n;i++) {
              ma = max(ma, A[i]);
              mi = min(mi, A[n-1-i]);
              if (A[i] < ma) end = i;
              if (A[n-1-i] > mi) beg = n-1-i; 
            }
            return end - beg + 1;
    }
};