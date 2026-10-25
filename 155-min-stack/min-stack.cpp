class MinStack { // Method 2 - no extra stack
    stack<long long> st;
    long long mn;
public:
    MinStack() { 
        mn = LLONG_MAX;
    }
    
    void push(long long value) {
        long long val = value;
        if(st.size() == 0) {
            st.push(val);
            mn = val;
        }
        else{
            if(val >= mn) st.push(val);
            else{
                st.push(val + (val - mn));
                mn = val;
            }
        }
    }
    
    void pop() {
        if(mn > st.top()){
            long long oldmin = 2*mn - st.top();
            mn = oldmin;
        }
        st.pop();
        
    }
    
    long long top() {
        if(mn > st.top() ) return mn;
        else return st.top();
    }
    
    long long getMin() {
        return mn;
    }
};// Method 1 - using extra stzck
// stack<int> st;
// stack<int> minSt;
// public:
//     MinStack() {
        
//     }

//     void push(int value) {
//         st.push(value);
//         if( minSt.size() == 0 || value < minSt.top()) minSt.push(value);
//         else minSt.push(minSt.top());
//     }

//     void pop() {
//         st.pop();
//         minSt.pop();
        
//     }

//     int top() {
//         return st.top();
//     }

//     int getMin() {
//         return minSt.top();
// }