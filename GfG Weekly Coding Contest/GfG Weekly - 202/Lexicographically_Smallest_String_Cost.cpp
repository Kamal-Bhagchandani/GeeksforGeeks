//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://practice.geeksforgeeks.org/contest/gfg-weekly-202-rated-contest/problems
*/

// User function Template for C++
class Solution {
  public:
    int minCost(string& s, int k) {
        // code here
        int n=s.size();
        int temp=0;
        int sum=0;
        if (k>26 && n>26) return -1;
        string str="abcdefghijklmnopqrstuvwxyz";
        for (int i=0;i<n;i++){
            sum+=abs(s[i]-str[temp]);
            if (temp==k-1) temp=0;
            else temp++;
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.minCost(s, k) << endl;
    }
}
// } Driver Code Ends