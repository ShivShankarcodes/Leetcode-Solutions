class MyStack {
    queue<int> q;
     int length ;
public:
    MyStack() {
        length = 0;
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        length++;

        for(int i=0;i<n;i++){ // Rotate Queue
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        length--;
        return val;
    }
    
    int top() {
        if (!q.empty()) 
            return q.front();
        return -1;
    }
    
    bool empty() {
        if(length == 0) return true;
        else return false;
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