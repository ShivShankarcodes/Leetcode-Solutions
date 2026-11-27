class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long n = x;
        int r;
        long long sum = 0;
        while(x>0){
            r = x%10;
            sum = sum * 10 + r;
            x /= 10;
        }
        return (sum == n);
    }
};