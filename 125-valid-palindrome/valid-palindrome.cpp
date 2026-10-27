class Solution {
public:
    bool isPalindrome(string s) { // method-2
        int n = s.size();
        int i=0 , j=n-1;
        while(i <j){
            while(i<j && !isalnum(s[i])) i++;
            while(i<j && !isalnum(s[j])) j--;

            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};  // Method-1
// bool notValid(char ch){
//     if(ch>=65 && ch<=90) return false;
//     else if(ch>=97 && ch<=122) return false;
//     else if (ch>=48 && ch<=57) return false;
//     else return true;
//     }
// bool isPalindrome(string s) {
//     int n = s.length();
//     int i=0 , j=n-1;
//     while(i<j){
//         char x=s[i] , y=s[j];
//         if(x>=65 && x<=90) x+=32;
//         if(y>=65 && y<=90) y+=32;
//         if(notValid(x)) i++;
//         else if (notValid(y)) j--;
//         else {
//             if(x!=y) return false ;
//             i++;
//             j--; 
//         }
//     }
//     return true;
// }