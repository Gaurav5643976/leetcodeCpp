class MedianFinder {
public:
    priority_queue<int,vector<int>> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    int sz1=0,sz2=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq1.push(num);
        sz1++;
        if(sz1>sz2+1){
            pq2.push(pq1.top());
            pq1.pop();
            sz1--;
            sz2++;
        }
        if(sz2 and pq1.top()>=pq2.top()){
            int temp=pq1.top();
            pq1.pop();
            pq1.push(pq2.top());
            pq2.pop();
            pq2.push(temp);
        }
    }
    
    double findMedian() {
        int sz=sz1+sz2;
        double ans=1;
        if(sz&1){
            ans=ans*pq1.top();
        }
        else{
            ans=ans*(pq1.top()+pq2.top())/2;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */