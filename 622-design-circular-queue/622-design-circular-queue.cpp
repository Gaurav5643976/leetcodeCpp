class MyCircularQueue {
public:
    vector<int>queue;
    int front,end;
    int size,capacity;
    MyCircularQueue(int k) {
        queue.resize(k,0);
        front=-1;
        end=-1;
        size=0;
        capacity=k;
    }
    
    bool enQueue(int value) {
        
        if(size==capacity)return false;
        
        if(size==0){
            front=0;
            end=0;
        }
        else if(end==capacity-1){
            end=0;
            queue[end]=value;
        }
        else{
            end++;
        }
        
        // cout<<end<<" ";
        queue[end]=value;
        size++;
        
        return true;        
    }
    
    bool deQueue() {
        if(size==0)return false;
        
        if(front==capacity-1){
            front=0;
        }
        else{
            front++;
        }
        size--;
        return true;
    }
    
    int Front() {
        if(size==0)return -1;
        return queue[front];
    }
    
    int Rear() {
        if(size==0)return -1;
        return queue[end];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */