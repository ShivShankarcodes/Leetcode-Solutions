class MyQueue {
    stack<int> st;
    stack<int> stk;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
       st.push(x);
    }
    
    int pop() {
        if(stk.empty()){
            while(!st.empty()){
                stk.push(st.top());
                st.pop();
            }
        }
        if(stk.empty()) return -1;
        int val = stk.top();
        stk.pop();
        return val;
    }
    
    int peek() {
        if(stk.empty()){
            while(!st.empty()){
                stk.push(st.top());
                st.pop();
            }
        }
        if(stk.empty()) return -1;
        return stk.top();
    }
    
    bool empty() {
        return st.empty() && stk.empty();
    }
};