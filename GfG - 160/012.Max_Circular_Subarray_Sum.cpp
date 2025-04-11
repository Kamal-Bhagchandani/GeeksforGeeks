//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/max-circular-subarray-sum-1587115620
*/

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int totalSum,currMaxSum,currMinSum,maxSum,minSum;
        totalSum=currMaxSum=currMinSum=0;
        maxSum=minSum=arr[0];
        for (int i=0;i<arr.size();i++){
            currMaxSum=max(currMaxSum+arr[i],arr[i]);
            maxSum=max(currMaxSum,maxSum);
            currMinSum=min(currMinSum+arr[i],arr[i]);
            minSum=min(currMinSum,minSum);
            totalSum+=arr[i];
        }
        int normalSum=maxSum;
        int circularSum=totalSum-minSum;
        if (minSum==totalSum) return normalSum;
        return max(circularSum,normalSum);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends