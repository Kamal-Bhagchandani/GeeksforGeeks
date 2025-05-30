//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/number-of-occurrence2259
*/

class Solution {
  public:
    int lowerBound(vector<int>& arr,int target){
        int res=arr.size();
        int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>=target){
                res=mid;
                hi=mid-1;
            }
            else lo = mid + 1;
        }
        return res;
    }
    
    int upperBound(vector<int>& arr,int target){
        int res=arr.size();
        int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>target){
                res=mid;
                hi=mid-1;
            }
            else lo = mid + 1;
        }
        return res;
    }
    
    int countFreq(vector<int>& arr, int target) {
        // code here
        return upperBound(arr,target) - lowerBound(arr,target);
    }
};class Solution {
  public:
    int lowerBound(vector<int>& arr,int target){
        int res=arr.size();
        int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>=target){
                res=mid;
                hi=mid-1;
            }
            else lo = mid + 1;
        }
        return res;
    }
    
    int upperBound(vector<int>& arr,int target){
        int res=arr.size();
        int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>target){
                res=mid;
                hi=mid-1;
            }
            else lo = mid + 1;
        }
        return res;
    }
    
    int countFreq(vector<int>& arr, int target) {
        // code here
        return upperBound(arr,target) - lowerBound(arr,target);
    }
};class Solution {
  public:
    int lowerBound(vector<int>& arr,int target){
        int res=arr.size();
        int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>=target){
                res=mid;
                hi=mid-1;
            }
            else lo = mid + 1;
        }
        return res;
    }
    
    int upperBound(vector<int>& arr,int target){
        int res=arr.size();
        int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>target){
                res=mid;
                hi=mid-1;
            }
            else lo = mid + 1;
        }
        return res;
    }
    
    int countFreq(vector<int>& arr, int target) {
        // code here
        return upperBound(arr,target) - lowerBound(arr,target);
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
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends