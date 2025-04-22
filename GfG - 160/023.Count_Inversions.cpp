//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/inversion-of-array-1587115620
*/

class Solution {
  public:
    int countInvAndMerge(vector<int>& arr,int l,int m,int r){
        int n1=m-l+1;
        int n2=r-m;
        vector<int> leftArr(arr.begin()+l,arr.begin()+m+1);
        vector<int> rightArr(arr.begin()+m+1,arr.begin()+r+1);
        int sum=0;
        int k=l;
        int i=0, j=0;
        for(;i<n1 && j<n2;){
            if(leftArr[i]<=rightArr[j]){
                arr[k]=leftArr[i];
                i++;
            }
            else{
                arr[k]=rightArr[j];
                sum+=(n1-i);
                j++;
            }
            k++;
        }
        while(i<n1){
            arr[k]=leftArr[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=rightArr[j];
            j++;
            k++;
        }
        return sum;
    }
    int countInv(vector<int>& arr,int l,int r){
        if(l>=r) return 0;
        int sum=0;
        int mid=(l+r)/2;
        sum+=countInv(arr,l,mid);
        sum+=countInv(arr,mid+1,r);
        sum+=countInvAndMerge(arr,l,mid,r);
        return sum;
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return countInv(arr,0,arr.size()-1);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends