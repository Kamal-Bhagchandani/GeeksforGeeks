//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/minimum-characters-to-be-added-at-front-to-make-string-palindrome
*/

class Solution {
  public:
    void computeLPS(string &pat,vector<int> &lps){
        int length=0;
        lps[0]=0;
        int i=1;
        int n=pat.length();
        while(i<n){
            if(pat[i]==pat[length]){
                length++;
                lps[i]=length;
                i++;
            }
            else{
                if(length!=0) length =lps[length-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    int minChar(string& s) {
        // Write your code here
        int n=s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        s=(string)s+"$"+rev;
        vector<int> lps(s.length(),0);
        computeLPS(s,lps);
        return n-lps.back();
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends