//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://practice.geeksforgeeks.org/contest/gfg-weekly-204-rated-contest/problems
*/

class Solution {
  public:
    long long countPairs(vector<int>& arr) {
        // code here
        unordered_map<int,long long> m;
        long long cnt=0;
        for(int i=0;i<arr.size();i++) m[arr[i]-i]++;
        for(auto it : m) cnt+=it.second*(it.second-1);
        return cnt;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        long long ans = ob.countPairs(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends