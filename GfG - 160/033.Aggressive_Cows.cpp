//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/aggressive-cows
*/

// User function Template for C++

class Solution {
  public:
    int check(vector<int> &stalls,int k,int dist){
        int cnt=1;
        int prev = stalls[0];
        for(int i=1;i<stalls.size();i++){
            if (stalls[i]-prev>=dist){
                prev=stalls[i];
                cnt++;
            }
        }
        return cnt>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int res=0;
        int lo=1,hi=stalls.back()-stalls[0];
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if (check(stalls,k,mid)){
                res = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends