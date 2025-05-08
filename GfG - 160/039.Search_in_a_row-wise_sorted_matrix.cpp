//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-row-wise-sorted-matrix
*/

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool binarySearch(vector<int> &arr,int x){
        int lo=0;
        int hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==x)return true;
            else if(x<arr[mid]) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        for(auto &row : mat){
            if (binarySearch(row,x)) return true;
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends