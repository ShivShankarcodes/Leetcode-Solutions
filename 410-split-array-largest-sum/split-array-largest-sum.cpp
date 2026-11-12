class Solution {
public:
    bool isValid(vector<int> &arr, int k,int n, long long mid){
        int student = 1 ;
        long long pages = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > mid) return false;
            if(pages + arr[i] <= mid){
                pages += arr[i];
            }else{
                student++;
                pages = arr[i];
            }
        }
        if(student > k) return false;
        else return true;
    }

    int splitArray(vector<int>& arr, int k) {
         int n = arr.size();
        
        if(k>n) return -1;
        
       long long sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        long long ans = -1;
        long long start = 0 , end = sum;
        while(start <= end){
            long mid = start + (end - start)/2;
            if(isValid(arr , k, n, mid)){
                ans = mid;
               end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return (int)ans;
    }
};