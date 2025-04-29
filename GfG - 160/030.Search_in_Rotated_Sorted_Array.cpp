//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/search-in-a-rotated-array4618
*/

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        int lo=0, hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==key) return mid;
            if(arr[lo]<=arr[mid]){
                if(key<arr[mid] && key>=arr[lo]) hi=mid-1;
                else lo=mid+1;
            }
            else{
                if(key>arr[mid] && key<=arr[hi]) lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends