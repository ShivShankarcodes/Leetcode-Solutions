class Solution {
public:
        // TC = O(nlogn)
    int majorityElement(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        int freq = 1 , ans = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i] == arr[i-1]) freq++;
            else{
                freq = 1;
                ans = arr[i];
            }
            if(freq > n/2) return ans;
        }
        return ans;
    }
};