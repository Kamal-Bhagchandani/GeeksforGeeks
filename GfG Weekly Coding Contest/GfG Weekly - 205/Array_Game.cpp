//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://practice.geeksforgeeks.org/contest/gfg-weekly-205-rated-contest/problems
*/

// User function template for C++

class Solution {
  public:
    bool arrayGame(vector<int>& arr) {
        // code here
        int n= arr.size();
        sort(arr.rbegin(),arr.rend());
        long long a,b;
        a=b=0;
        for(int i=0;i<n;i++){
            if (n%2==0){
                if(i<n/2) a+=arr[i];
                else b+=arr[i];
            }
            else{
                if(i<=n/2) a+=arr[i];
                else b+=arr[i];
            }
        }
        return (a>b);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << (obj.arrayGame(a) ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends