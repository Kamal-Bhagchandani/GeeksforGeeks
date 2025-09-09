/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/maximize-number-of-1s0905
*/

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int res=0;
        int start=0,end=0;
        int zeroCnt=0;
        
        while(end<arr.size()){
            if(arr[end]==0)
                zeroCnt++;
            
            while(zeroCnt>k){
                if(arr[start]==0)
                    zeroCnt--;
                start++;
            }
            if(end-start+1>res)
                res=end-start+1;
            end++;
        }
        
        return res;
    }
};
