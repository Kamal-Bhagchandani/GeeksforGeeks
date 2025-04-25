//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/non-overlapping-intervals
*/

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int cnt=0;
        sort(intervals.begin(),intervals.end(),
        [](const vector<int>& a,const vector<int>& b){
               return a[1]<b[1];
        });
        int end = intervals[0][1];
        for (int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                cnt++;
                end=min(end,intervals[i][1]);
            }
            else end = intervals[i][1];
        }
        return cnt;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends