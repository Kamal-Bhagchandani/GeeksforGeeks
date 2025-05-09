//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-matrix-1587115621
*/

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int lo=0,hi=n*m-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int row=mid/m,col=mid%m;
            if(mat[row][col]==x) return true;
            else if(mat[row][col]<x) lo=mid+1;
            else hi=mid-1;
        }
        return false;
    }
};

/*  Using Binary Search 2 times:    (Slightly less optimal)
(First to find the row and 2nd to find whether the number is there or not)
Therefore, Time Complexity: O(log(n)+log(m)) or O(log(nm))
class Solution {
  public:
    bool binarySearch(vector<int> &arr,int x){
        int n=arr.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==x) return true;
            else if(arr[mid]<x) lo = mid+1;
            else hi=mid-1;
        }
        return false;
    }
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size();
        int lo=0,hi=n-1;
        int row=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mat[mid][0]==x) return true;
            else if(mat[mid][0]<x){
                row=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        if(row==-1) return false;
        return binarySearch(mat[row],x);
    }
};
*/

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
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends