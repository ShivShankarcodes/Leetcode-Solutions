class Solution {
public:
    double myPow(double x2, int n) { // Method 2
        if(n == 0) return 1.0;
        if(x2 == 0) return 0.0;
        if(x2 == 1) return 1.0;
        if(x2 == -1 && n%2 == 0) return 1.0;
        if(x2 == -1 && n%2 == 1) return -1.0;
        long long binary = n;
        long double x = x2;
        if(n < 0){
            x = 1.0/x;
            binary = -binary;
        }
        double ans = 1.0;
        while(binary > 0){
            if(binary %2 == 1){
                ans *= x;
            }
            x *= x;
            binary /= 2;
        } 
        return (double)ans;
    }
}; // Method 1
// double power(double x, long long n){
//     if(n==0) return 1;
//     double p = power(x,n/2);
//     if(n%2==0) return p*p;
//     else return p*p*x;
// }
// double myPow(double x, long long n) {
//     bool flag=(n>=0);
//     double ans = power(x,abs(n));
//     if(flag==false) ans=1/ans;
//     return ans;
// }