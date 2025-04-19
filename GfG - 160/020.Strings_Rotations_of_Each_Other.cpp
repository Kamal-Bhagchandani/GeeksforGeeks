//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/check-if-strings-are-rotations-of-each-other-or-not-1587115620
*/

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    void computeLPS(string &pat,vector<int>&lps){
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
                if(length!=0) length = lps[length-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    bool areRotations(string &s1, string &s2) {
        // Your code here
        string txt=s1+s1;
        string pat=s2;
        int n=txt.length();
        int m=pat.length();
        vector<int>lps(m,0);
        computeLPS(pat,lps);
        
        int i=0,j=0;
        while(i<n){
            if(txt[i]==pat[j]){
                i++;
                j++;
            }
            if(j==m) return true;
            else if(txt[i]!=pat[j]){
                if(j!=0) j=lps[j-1];
                else{
                    i++;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends