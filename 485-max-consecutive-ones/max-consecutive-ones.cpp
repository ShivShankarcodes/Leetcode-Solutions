class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int maxOne = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1) ones++;
            else {
                maxOne = max(ones,maxOne);
                ones = 0;
            }
        }
        return max(maxOne,ones);
    }
};