class Solution { // Method-2 using deque
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
       int n = arr.size();
       deque<int> dq;
       for(int i=0;i<k;i++){ // first window element
        while(dq.size() > 0 && arr[dq.back()] < arr[i]) dq.pop_back();
        dq.push_back(i);
       }
       vector<int> ans(n-k+1);
       ans[0] = arr[dq.front()]; 
       for(int i=k;i<n;i++){ // i is the end of window
        int j = i-k+1;       // j is the start of windoe
        while(dq.size() > 0 && arr[dq.back()] < arr[i]) dq.pop_back();
        dq.push_back(i);

        while(dq.size() > 0 && dq.front() <j) dq.pop_front();
        ans[j] = arr[dq.front()];
       }
       return ans;
    }
};
    // Method-1 using stack
// int n = arr.size();
// // next greater element (index)
// vector<int> nse(n,-1);
// stack<int> st;
// for(int i=n-1;i>=0;i--){
//     while(st.size() > 0 && arr[st.top()] <= arr[i]) st.pop();
//     if(st.size() != 0) nse[i] = st.top();
//     st.push(i);
// }
// vector<int> ans(n-k+1);
// int j =0;
// for(int i=0;i<n-k+1;i++){
//     if(j<i) j=i;
//     while(nse[j] != -1 && nse[j] < i+k) 
//         j = nse[j];
//     ans[i] = (arr[j]);
// }
// return ans;