/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-bonus-problem/problem/combination-sum-ii-1664263832
*/

class Solution {
  private:
    void findCombinations(vector<int> &arr, int index, int target,
                vector<int> &curr, vector<vector<int>> &res){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        
        if(target < 0 || index >= arr.size()) return;
        
        for(int i = index; i<arr.size(); i++){
            if(i > index && arr[i] == arr[i-1])
                continue;
            curr.push_back(arr[i]);
            
            findCombinations(arr, i+1, target - arr[i], curr, res);
            curr.pop_back();
        }
    }
  public:
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> curr;
        
        findCombinations(arr, 0, target, curr, res);
        
        return res;
    }
};