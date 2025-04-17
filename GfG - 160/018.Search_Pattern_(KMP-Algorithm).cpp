//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/search-pattern0205
*/

class Solution {
  public:
    void computeLPS(string& pat,vector<int>& lps){
        int length = 0;
        lps[0]=0;
        int i=1;
        int m=pat.length();
        while(i<m){
            if(pat[i]==pat[length]){
                length++;
                lps[i]=length;
                i++;
            }
            else{
                if(length != 0) length = lps[length-1];
                else {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    vector<int> search(string& pat, string& txt) {
        // code here
        int n=txt.length();
        int m=pat.length();
        vector<int>lps(m,0);
        vector<int>res;
        computeLPS(pat,lps);
        int i,j;
        i=j=0;
        while(i<n){
            if(txt[i]==pat[j]){
                i++;
                j++;
                if(j==m){
                    res.push_back(i-j);
                    j=lps[j-1];
                }
            }
            else{
                (j!=0)? j=lps[j-1] : i++;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends