//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n=arr.size();
        int ele1=-1,ele2=-1;
        int cnt1=0,cnt2=0;
        for (int ele : arr){
            if (ele1==ele) cnt1++;
            else if (ele2==ele) cnt2++;
            else if (cnt1==0){
                ele1=ele;
                cnt1++;
            }
            else if (cnt2==0){
                ele2=ele;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> arr2;
        cnt1=0,cnt2=0;
        for (int ele : arr){
            if (ele1==ele) cnt1++;
            if (ele2==ele) cnt2++;
        }
        if (cnt1>n/3) arr2.push_back(ele1);
        if (cnt2>n/3 && ele1!=ele2) arr2.push_back(ele2);
        if (arr2.size()==2 && arr2[0]>arr2[1]) swap(arr2[0],arr2[1]);
        return arr2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends