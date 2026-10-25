class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        // next greater element (index)
        vector<int> nse(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && arr[st.top()] <= arr[i]) st.pop();
            if(st.size() != 0) nse[i] = st.top();
            st.push(i);
        }
        vector<int> ans(n-k+1);
        int j =0;
        for(int i=0;i<n-k+1;i++){
            if(j<i) j=i;
            while(nse[j] != -1 && nse[j] < i+k) 
                j = nse[j];
           ans[i] = (arr[j]);
        }
        return ans;
    }
};