/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/split-array-in-three-equal-sum-subarrays
*/

// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans;
        
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        
        if(totalSum%3!=0) return {-1,-1};
        int target = totalSum/3;
        
        int currSum=0;
        
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            
            if(currSum==target){
                currSum=0;
                ans.push_back(i);
                if(ans.size()==2 && i<n-1){
                    return ans;
                }
            }
        }
        return {-1,-1};
    }
};