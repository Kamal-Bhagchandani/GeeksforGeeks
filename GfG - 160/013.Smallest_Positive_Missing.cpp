//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/smallest-positive-missing-number-1587115621
*/

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int small=1;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        auto last=unique(arr.begin(),arr.end());
        arr.erase(last,arr.end());
        for (int i=0;i<n;i++){
            if(arr[i]>0 && arr[i]==small){
                small++;
                continue;
            }
            else if(arr[i]>0 && arr[i]!=small) return small;
        }
        return small;
    }
};




//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends