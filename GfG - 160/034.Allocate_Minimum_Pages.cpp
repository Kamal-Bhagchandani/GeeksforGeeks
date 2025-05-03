//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/allocate-minimum-number-of-pages0937
*/

class Solution {
  public:
    bool check(vector<int> &arr,int k,int pagelimit){
        int cnt=1;
        int pageSum=0;
        for (int pages : arr){
            if((pages+pageSum)>pagelimit){
                cnt++;
                pageSum = pages;
            }
            else pageSum+=pages;
        }
        return cnt<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if (k>n) return -1;
        int lo=*max_element(arr.begin(),arr.end());
        int hi=accumulate(arr.begin(),arr.end(),0);
        int res=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if (check(arr,k,mid)){
                res=mid;
                hi = mid-1;
            }
            else lo=mid+1;
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

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends