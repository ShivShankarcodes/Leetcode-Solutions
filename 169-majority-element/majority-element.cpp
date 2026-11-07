class Solution {
public:
        // TC = O(n)  Moore's Algorithm
    int majorityElement(vector<int>& arr) {
       int n = arr.size();
       int freq = 0 , ans = 0;
       for(int i=0;i<n;i++){
        if(freq == 0) {
            ans = arr[i];
            freq = 1;
        }
        else if(ans == arr[i]) freq++;
        else freq--;
       }
       return ans;
    }
};
//  TC = O(nlogn)
// int majorityElement(vector<int>& arr) {
//     sort(arr.begin() , arr.end());
//     int n = arr.size();
//     int freq = 1 , ans = arr[0];
//     for(int i=1;i<n;i++){
//         if(arr[i] == arr[i-1]) freq++;
//         else{
//             freq = 1;
//             ans = arr[i];
//         }
//         if(freq > n/2) return ans;
//     }
//     return ans;