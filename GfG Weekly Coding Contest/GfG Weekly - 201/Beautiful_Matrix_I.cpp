//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    bool isBeauty(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        for (int j=0;j<m;j++){
            bool flag=false;
            int colSum=0;
            for (int i=0;i<n;i++){
                colSum+=mat[i][j];
            }
            for (int i=0;i<n;i++){
                if (mat[i][j]==colSum-mat[i][j]){
                    flag=true;
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        Solution obj;
        if (obj.isBeauty(v))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends