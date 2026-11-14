class Solution {
public:
    bool isPossible(vector<int>& arr, int& k , long long& mid){
        int painter = 1;
        long long time = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] + time <= mid){
                time += arr[i];
            }else{
                painter++;
                time = arr[i];
            }
        }
        if(painter > k) return false;
        else return true;
    }
    
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        long long sum = 0;
        long long max = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > max ) max = arr[i];
            sum += arr[i];
        }
        long long ans = -1;
        long long start = max , end = sum;
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(isPossible(arr,k,mid)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};