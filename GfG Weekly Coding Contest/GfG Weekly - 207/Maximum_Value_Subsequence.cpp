//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://practice.geeksforgeeks.org/contest/gfg-weekly-207-rated-contest/problems
*/

// User function Template for C++
class Solution {
  public:
    long long maxValue(vector<int>& arr) {
        // code here
        int n=arr.size();
        sort(arr.rbegin(),arr.rend());
        long long ans=0;
        for(int i=0;i<n;i++){
            int value=arr[i]-(i+1);
            if(value<=0) break;
            ans+=value;
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
        Solution ob;
        long long res = ob.maxValue(a);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends