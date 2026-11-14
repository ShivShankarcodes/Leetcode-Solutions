class Solution {
public:
    bool isPossible(vector<int>& position, int m,int n,int minDis){
        int balls = 1 , lastPos = position[0];
        for(int i=1;i<n;i++){
            if(position[i] - lastPos >= minDis){
                balls++;
                lastPos = position[i];
            }
            if(balls == m) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin() , position.end());

        int start = 1 , end = position[n-1] - position[0] , ans = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(position,m,n,mid)){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};