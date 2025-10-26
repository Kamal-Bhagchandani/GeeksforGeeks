/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-bonus-problem/problem/combination-sum-1587115620
*/

class Solution {
  private:
    void makeCombination(vector<int> &arr, int remSum, vector<int> &cur,
            vector<vector<int>> &res,int index){
        
        if(remSum == 0){
            res.push_back(cur);
            return;
        }
        
        if(remSum<0 || index>=arr.size()) return;
        
        cur.push_back(arr[index]);
        makeCombination(arr, remSum - arr[index], cur, res, index);
        
        cur.pop_back();
        makeCombination(arr, remSum, cur, res, index + 1);
    }
    
  public:
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        vector<int> cur;
        vector<vector<int>> res;
        
        makeCombination(arr, target, cur, res, 0);
        
        return res;
    }
};