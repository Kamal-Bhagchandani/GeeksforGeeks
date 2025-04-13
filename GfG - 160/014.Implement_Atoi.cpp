//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/implement-atoi
*/

class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int i=0;
        long result=0;
        int sign=1;
        while(s[i]==' '){
            i++;
        }
        if (s[i]=='+' || s[i]=='-'){
            if  (s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        while(s[i]>='0'&& s[i]<='9'){
            int digit=s[i]-'0';
            if  (result>(INT32_MAX-digit)/10){
                return (sign==1)? INT32_MAX : INT32_MIN;
            }
            result=result*10+digit;
            i++;
        }
        return (int)(result*sign);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends