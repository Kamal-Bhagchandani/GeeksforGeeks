//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-pairs-with-given-sum--150253
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int count = 0;
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            int complement = target - arr[i];
            if(m.find(complement)!=m.end()){
                count+=m[complement];
            }
            m[arr[i]]++;
        }
        return count;
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
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends