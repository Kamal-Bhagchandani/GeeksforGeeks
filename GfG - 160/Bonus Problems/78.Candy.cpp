/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-bonus-problems/problem/candy
*/

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n = arr.size();
        int total = n;
        int i = 1;
        
        while(i < n){
            if(arr[i] == arr[i - 1]){
                i++;
                continue;
            }
            
            int peak = 0;
            while(i < n && arr[i] > arr[i-1]){
                peak++;
                total += peak;
                i++;
            }
            
            if(i==n){
                return total;
            }
            
            int valley = 0;
            while(i < n && arr[i] < arr[i-1]){
                valley++;
                total += valley;
                i++;
            }
            total -= min(peak,valley);
        }
        
        return total;
    }
};
