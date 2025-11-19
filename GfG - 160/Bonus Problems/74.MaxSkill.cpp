/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dp-bonus-problems/problem/burst-balloons
*/

class Solution {
  private:
    int getMaxSkill(int left, int right, vector<int> &arr, vector<vector<int>> &memo){
        if(left > right)
            return 0;
        
        if(memo[left][right] != -1)
            return memo[left][right];
        
        int maxSkill = 0;
        
        for(int k = left; k <= right; k++){
            int skill = arr[left - 1] * arr[k] * arr[right + 1];
            
            int leftSkill = getMaxSkill(left, k - 1, arr, memo);
            int rightSkill = getMaxSkill(k + 1, right, arr, memo);
            
            maxSkill = max(maxSkill,skill + leftSkill + rightSkill);
        }
        memo[left][right] = maxSkill;
        
        return maxSkill;
    }
  public:
    int maxSkill(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
        
        return getMaxSkill(1, n, arr, memo);
    }
};