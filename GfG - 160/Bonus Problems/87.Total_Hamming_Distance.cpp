/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-bonus-problems/problem/total-hamming-distance
*/

// User function template for C++
class Solution {
  public:
    int totHammingDist(vector<int>& arr) {
        // code here
        int n = arr.size();
        int count = 0;
        vector<int> countOne(32, 0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++){
                
                if(arr[i] & (1 << j)){
                    countOne[j]++;
                }
            }
        }
        
        for(int j = 0; j < 32; j++){
            count += countOne[j] * (n - countOne[j]);
        }
        
        return count;
    }
};