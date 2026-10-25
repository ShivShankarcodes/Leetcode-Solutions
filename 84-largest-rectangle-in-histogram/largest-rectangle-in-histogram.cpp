class Solution {
public:
    int largestRectangleArea(vector<int>& arr) { // Method - 2
        int n =arr.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0;i<=n;i++){
            int currHeight = (i == n) ? 0 : arr[i];
            while( st.size() > 0 && arr[st.top()] > currHeight) {
                int h = arr[st.top()];
                st.pop();
                int w = st.empty() ? i : i-st.top()-1;
                int area = h * w;
                maxArea = max(area,maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }
}; // Method-1
// int n =arr.size();
//     // next smaller element(index)
//     stack<int> st;
//     vector<int> nsi(n);
//     for(int i=n-1;i>=0;i--){
//         while(st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();
//         if(st.size() != 0) nsi[i] = st.top();
//         else nsi[i] = n;
//         st.push(i);
//     }   
//     // previous smaller element (index)
//     while(st.size() > 0) st.pop();
//     vector<int> psi(n);
//     for(int i=0;i<n;i++){
//         while(st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();
//         if(st.size() != 0) psi[i] = st.top();
//         else psi[i] = -1;
//         st.push(i);
//     }
//     int maxArea = 0;
//     for(int i=0;i<n;i++){
//         int width = nsi[i] - psi[i] - 1;
//         int length = arr[i];
//         int area = length * width;
//         maxArea = max(area , maxArea);
//     }
//     return maxArea;
// }
