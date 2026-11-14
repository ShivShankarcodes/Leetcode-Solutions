class Solution {
public:
    bool canEat(vector<int>& piles,int h, int mid){
        long long tHours = 0;
        for(int i=0;i<piles.size();i++){
            int hours = (piles[i] + mid - 1)/mid;
            tHours += hours;
        }
        if(tHours <= h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int st = 1 , end = piles[n-1]; 
        int ans = 0;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(canEat(piles,h,mid)){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
};