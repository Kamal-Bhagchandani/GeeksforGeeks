//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Function returns the second largest elements
    int getSecondLargest(vector<int> &arr) {
        int max1 = 0;
        int max2 = 0;
        if (arr.size()<2) return -1;
        for (int num : arr){
            if (num>max1){
                max2 = max1;
                max1 = num;
            }
            else if(num>max2 && num!=max1){
                max2=num;
            }
        }
        if (max2==0) return -1;
        else return max2;
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
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends