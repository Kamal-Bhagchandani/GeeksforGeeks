//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/k-th-element-of-two-sorted-array1317
*/

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int m=a.size(),n=b.size();
        if (n>m) return kthElement(b,a,k);
        
        int lo=max(0,k-n);
        int hi=min(k,m);
        
        while(lo<=hi){
            int mid1=(lo+hi)/2;
            int mid2=k-mid1;
            
            int l1 = (mid1==0)? INT_MIN : a[mid1-1];
            int r1 = (mid1==m)? INT_MAX : a[mid1];
            int l2 = (mid2==0)? INT_MIN : b[mid2-1];
            int r2 = (mid2==n)? INT_MAX : b[mid2];
            
            if(l1<=r2 && l2<=r1) return max(l1,l2);
            else if(l1>r2) hi=mid1-1;
            else lo=mid1+1;
        }
        return 0;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends