//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/anagram-1587115620
*/

class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        unordered_map<char,int> m;
        for (int i=0;i<s1.length();i++){
            m[s1[i]]++;
        }
        for (int i=0;i<s2.length();i++){
            m[s2[i]]--;
        }
        for(auto i:m){
            if (i.second!=0) return false;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends