class Solution {
public:
    int missingNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i] != i)
                return i;
        }
        return arr.size();
    }

        // Method-2
    // int missingNumber(vector<int>& nums) {
    //     int n=nums.size();
    //     int sum1=0;
    //     for(int i=0; i<n; i++){
    //         sum1+=nums[i];
        
    //     }
    //     int sum2 = (n*(n+1))/2;
    //     return sum2-sum1;
    // }
};