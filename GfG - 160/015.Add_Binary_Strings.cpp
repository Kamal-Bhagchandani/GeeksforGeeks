//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/add-binary-strings3805
*/

// User function template for C++
class Solution {
  public:
    string rem0(string &s){
        int firstOne=s.find('1');
        if (firstOne!=-1) return s.substr(firstOne);
        else return "0";
    }
    string addBinary(string& s1, string& s2) {
        // your code here
        s1=rem0(s1);
        s2=rem0(s2);
        int n=s1.length();
        int m=s2.length();
        
        if (n<m){
            swap(s1,s2);
            swap(n,m);
        }
        int j=m-1;
        int carry=0;
        vector<char> result;
        for (int i=n-1;i>=0;i--){
            int bit1=s1[i]-'0';
            int bitSum=bit1+carry;
            if(j>=0){
                int bit2=s2[j]-'0';
                bitSum+=bit2;
                j--;
            }
            int bit=bitSum%2;
            carry=bitSum/2;
            result.push_back(bit+'0');
        }
        if(carry>0){
            result.push_back('1');
        }
        reverse(result.begin(),result.end());
        return string(result.begin(),result.end());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends