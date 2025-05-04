//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://practice.geeksforgeeks.org/contest/gfg-weekly-205-rated-contest/problems
*/

// User function Template for C++
class Solution {
  public:
    int longestSubsequence(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int ans=1;
        for (int i=0;i<n-1;i++){
            if(arr[i]%k!=arr[i+1]%k){
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int v;
        vector<int> a;
        while (ss >> v) {
            a.push_back(v);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.longestSubsequence(a, k) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends