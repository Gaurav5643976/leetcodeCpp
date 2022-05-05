class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    int helper(bool i){
        int ans;
        while(!q1.empty()){
            if(q1.size()==1){
                ans=q1.front();
                if(i){
                    q1.pop();
                }
                else{
                    q2.push(q1.front());
                    q1.pop();
                }
            }
            else{
                q2.push(q1.front());
                q1.pop();
            }
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        return helper(true);
    }
    
    /** Get the top element. */
    int top() {
        return helper(false);
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */