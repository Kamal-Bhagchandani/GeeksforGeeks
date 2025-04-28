//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/minimum-element-in-a-sorted-and-rotated-array3611
*/

class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int lo=0,hi=arr.size()-1;
        while(lo<hi){
            if(arr[lo]<arr[hi]) return arr[lo];
            int mid=(lo+hi)/2;
            if(arr[mid]>arr[hi]) lo = mid + 1;
            else hi = mid;
        }
        return arr[lo];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends