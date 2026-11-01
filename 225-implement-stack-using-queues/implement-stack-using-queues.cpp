class MyStack {
    queue<int> q;
     int length = 0;
public:
    MyStack() {
    }

    // Method 1
        void push(int x) { // TC = O(1)
            q.push(x);
            length++;
        }
        int pop() { // TC = O(N)
            int n = q.size();
            for(int i=0;i<n-1;i++){
                q.push(q.front());
                q.pop();
            }
            int val = q.front();
            q.pop();
            length--;
            return val;
        }
        int top() {  // TC = O(N)
            if (q.empty())  return -1;

            int n = q.size();
            for(int i=0;i<n-1;i++){
                q.push(q.front());
                q.pop();
            }
            int val = q.front();
            q.push(q.front());
            q.pop();
            return val;
        }

    // Method 2
        // void push(int x) { // TC = O(N)
        //     int n = q.size();
        //     q.push(x);
        //     length++;

        //     for(int i=0;i<n;i++){ // Rotate Queue
        //         q.push(q.front());
        //         q.pop();
        //     }
        // }
        
        // int pop() { // TC = O(1)
        //     int val = q.front();
        //     q.pop();
        //     length--;
        //     return val;
        // }
        
        // int top() {  // TC = O(1)
        //     if (!q.empty()) 
        //         return q.front();
        //     return -1;
        // }
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