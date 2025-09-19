/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-bonus-problems/problem/largest-number-formed-from-an-array1117
*/

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        string ans="";
        int n=arr.size();
        
        sort(arr.begin(),arr.end(),[](const int &a,const int &b){
            string A=to_string(a);
            string B=to_string(b);
            return B+A < A+B;
        });
        
        // To avoid case where all the numbers in array are 0:
        if(arr[0]==0) return "0";   
        
        for(int val:arr) ans+=to_string(val);
        
        return ans;
    }
};