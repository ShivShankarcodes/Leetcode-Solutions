class Solution {
public:

    bool isValid(vector<int>& candies, long long k , int n , long long mid){
        long long children = 0;
        for(int i=0;i<n;i++){
            children += candies[i] / mid;

            if( children >= k)  return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += candies[i];
        }
        long long ans = 0;
        long long l = 1 , r = sum/k;
        while(l <= r){
            long long mid = l + (r-l)/2;
            if(isValid(candies,k,n,mid)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};