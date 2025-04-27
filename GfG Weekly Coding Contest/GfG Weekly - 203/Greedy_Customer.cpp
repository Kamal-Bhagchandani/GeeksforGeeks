//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://practice.geeksforgeeks.org/contest/gfg-weekly-203-rated-contest/problems
*/

// User function Template for C++
class Solution {
  public:
    long long maxDiscount(vector<int>& prices, vector<vector<int>>& options) {
        // code here
        long long minprice=0;
        sort(prices.begin(),prices.end(),greater<int>());
        for (auto &option : options){
            int x = option[0];
            int y = option[1];
            x=min(x,(int)prices.size());
            vector<int> topPrices(prices.begin(),prices.begin()+x);
            sort(topPrices.begin(),topPrices.end());
            for(int i=0;i<y;i++){
                minprice+=topPrices[i];
            }
        }
        return minprice;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string s;
        getline(cin, s);
        stringstream ss(s);
        int val;
        while (ss >> val) {
            prices.push_back(val);
        }

        int q;
        cin >> q;
        cin.ignore();
        vector<vector<int>> options(q, vector<int>(2));
        for (int i = 0; i < q; i++) {
            cin >> options[i][0] >> options[i][1];
        }
        cin.ignore();

        Solution obj;
        long long result = obj.maxDiscount(prices, options);
        cout << result << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends