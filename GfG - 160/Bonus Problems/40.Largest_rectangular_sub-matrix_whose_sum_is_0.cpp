/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-bonus-problem/problem/largest-rectangular-sub-matrix-whose-sum-is-0
*/

// User function Template for C++

class Solution {
  private:
    int maxZeroSumSubarray(vector<int> &arr){
        int prefSum=0;
        int maxLen=0;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr.size();i++){
            prefSum+=arr[i];
            if(prefSum==0)
                maxLen=i+1;
            if(mp.find(prefSum)!=mp.end())
                maxLen = max(maxLen,i-mp[prefSum]);
            else
                mp[prefSum]=i;
        }
        
        return maxLen;
    }
  public:
    int zeroSumSubmat(vector<vector<int>>& mat) {
        // Code Here
        int rows = mat.size();
        int cols = mat[0].size();
        int maxArea = 0;
        
        for(int i=0;i<rows;i++){
            vector<int> temp(cols,0);
            for(int j=i;j<rows;j++){
                for(int k=0;k<cols;k++){
                    temp[k]+=mat[j][k];
                }
                int len = maxZeroSumSubarray(temp);
                maxArea = max(maxArea,(j-i+1)*len);
            }
        }
        
        return maxArea;
    }
};
